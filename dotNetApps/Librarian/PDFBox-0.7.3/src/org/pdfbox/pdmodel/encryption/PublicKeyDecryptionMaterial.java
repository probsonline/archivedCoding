/**
 * Copyright (c) 2003-2005, www.pdfbox.org
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of pdfbox; nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * http://www.pdfbox.org
 *
 */

package org.pdfbox.pdmodel.encryption;

import java.security.Key;
import java.security.KeyStore;
import java.security.KeyStoreException;
import java.security.NoSuchAlgorithmException;
import java.security.UnrecoverableKeyException;
import java.security.cert.X509Certificate;
import java.util.Enumeration;

/**
 * This class holds necessary information to decrypt a PDF document 
 * protected by the public key security handler.
 * 
 * To decrypt such a document, we need:
 * <ul>
 * <li>a valid X509 certificate which correspond to one of the recipient of the document</li>
 * <li>the private key corresponding to this certificate
 * <li>the password to decrypt the private key if necessary</li> 
 * </ul>
 * 
 * Objects of this class can be used with the <code>openProtection</code> method of <code>PDDocument</code>.
 * 
 * The following example shows how to decrypt a document using a PKCS#12 certificate 
 * (typically files with a pfx extension).
 *  
 * <pre>
 * PDDocument doc = PDDocument.load(document_path);
 * KeyStore ks = KeyStore.getInstance("PKCS12");
 * ks.load(new FileInputStream(certificate_path), password.toCharArray());
 * PublicKeyDecryptionMaterial dm = new PublicKeyDecryptionMaterial(ks, null, password);
 * doc.openProtection(dm);
 * </pre>
 * 
 * In this code sample certificate_path contains the path to the PKCS#12 certificate.  
 * 
 * @see org.pdfbox.pdmodel.PDDocument#openProtection(DecryptionMaterial)
 * 
 * @author Benoit Guillon (benoit.guillon@snv.jussieu.fr)
 * @version $Revision: 1.2 $
 */

public class PublicKeyDecryptionMaterial extends DecryptionMaterial 
{
    private String password = null;
    private KeyStore keyStore = null;
    private String alias = null;
        
    /**
     * Create a new public key decryption material.
     * 
     * @param keystore The keystore were the private key and the certificate are
     * @param a The alias of the private key and the certificate.  
     *   If the keystore contains only 1 entry, this parameter can be left null.  
     * @param pwd The password to extract the private key from the keystore. 
     */
    
    public PublicKeyDecryptionMaterial(KeyStore keystore, String a, String pwd)
    {
        keyStore = keystore;
        alias = a;
        password = pwd;
    }
        
    
    /**
     * Returns the certificate contained in the keystore.
     * 
     * @return The certificate that will be used to try to open the document.
     * 
     * @throws KeyStoreException If there is an error accessing the certificate.
     */
    
    public X509Certificate getCertificate() throws KeyStoreException
    {
        if(keyStore.size() == 1)
        {
            Enumeration aliases = keyStore.aliases();
            String keyStoreAlias = (String)aliases.nextElement();
            return (X509Certificate)keyStore.getCertificate(keyStoreAlias);
        }
        else
        {
            if(keyStore.containsAlias(alias))
            {
                return (X509Certificate)keyStore.getCertificate(alias);
            }
            throw new KeyStoreException("the keystore does not contain the given alias");
        }
    }
    
    /**
     * Returns the password given by the user and that will be used 
     * to open the private key.
     * 
     * @return The password.
     */
    public String getPassword()
    {
        return password;
    }
    
    /**
     * returns The private key that will be used to open the document protection.
     * @return The private key.
     * @throws KeyStoreException If there is an error accessing the key.
     */
    public Key getPrivateKey() throws KeyStoreException 
    {
        try
        {
            if(keyStore.size() == 1)
            {
                Enumeration aliases = keyStore.aliases();
                String keyStoreAlias = (String)aliases.nextElement();
                return keyStore.getKey(keyStoreAlias, password.toCharArray());
            }
            else
            {
                if(keyStore.containsAlias(alias))
                {
                    return keyStore.getKey(alias, password.toCharArray());
                }
                throw new KeyStoreException("the keystore does not contain the given alias");
            }
        }
        catch(UnrecoverableKeyException ex)
        {
            throw new KeyStoreException("the private key is not recoverable");
        }
        catch(NoSuchAlgorithmException ex)
        {
            throw new KeyStoreException("the algorithm necessary to recover the key is not available");
        }
    }
}