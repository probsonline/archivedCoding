package org.pdfbox.searchengine.lucene;

/*
 * This source was originally written as an example for the lucene project.
 * It has been modified to use PDFBox as a  lucene document creator.
 * -Ben Litchfield
 *
 *====================================================================
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 2001 The Apache Software Foundation.  All rights
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. The end-user documentation included with the redistribution,
 *    if any, must include the following acknowledgment:
 *       "This product includes software developed by the
 *        Apache Software Foundation (http://www.apache.org/)."
 *    Alternately, this acknowledgment may appear in the software itself,
 *    if and wherever such third-party acknowledgments normally appear.
 *
 * 4. The names "Apache" and "Apache Software Foundation" and
 *    "Apache Lucene" must not be used to endorse or promote products
 *    derived from this software without prior written permission. For
 *    written permission, please contact apache@apache.org.
 *
 * 5. Products derived from this software may not be called "Apache",
 *    "Apache Lucene", nor may "Apache" appear in their name, without
 *    prior written permission of the Apache Software Foundation.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE APACHE SOFTWARE FOUNDATION OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Software Foundation.  For more
 * information on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */

import org.apache.lucene.analysis.standard.StandardAnalyzer;

import org.apache.lucene.demo.HTMLDocument;

import org.apache.lucene.document.Document;

import org.apache.lucene.index.IndexReader;
import org.apache.lucene.index.IndexWriter;
import org.apache.lucene.index.Term;
import org.apache.lucene.index.TermEnum;

import java.util.Arrays;


import java.io.File;
import java.io.IOException;

import java.util.Date;


/**
 * This is a class that will index some files on a local filesystem.  This code
 * was modified from a demo that comes with the lucene search engine.
 *
 * @author Lucene team
 * @author <a href="mailto:ben@benlitchfield.com">Ben Litchfield</a>
 *
 * @version $Revision: 1.8 $
 */
public class IndexFiles
{
    private boolean deleting = false;     // true during deletion pass
    private IndexReader reader;       // existing index
    private IndexWriter writer;       // new index being built
    private TermEnum uidIter;         // document id iterator

    /**
     * This is the main entry point for the indexer.
     *
     * @param argv The command line arguments.
     */
    public static void main(String[] argv)
    {

        String index = "index";
        boolean create = false;
        File root = null;

        String usage = "org.pdfbox.searchengine.lucene.IndexFiles [-create] [-index <index>] <root_directory>";

        if (argv.length == 0)
        {
            System.err.println("Usage: " + usage);
            return;
        }

        for (int i = 0; i < argv.length; i++)
        {
            if (argv[i].equals("-index"))
            {         // parse -index option
                index = argv[++i];
            }
            else if (argv[i].equals("-create"))
            {     // parse -create option
                create = true;
            }
            else if (i != argv.length-1)
            {
                System.err.println("Usage: " + usage);
                return;
            }
            else
            {
                System.out.println( "root=" +argv[i] );
                root = new File(argv[i]);
            }
        }
        IndexFiles indexer = new IndexFiles();
        indexer.index( root, create, index );
    }

    /**
     * This will index a directory.
     *
     * @param root The root directory to start indexing.
     * @param create Should we create a new index?
     * @param index The name of the index.
     */
    public void index( File root, boolean create, String index )
    {

        try
        {
            Date start = new Date();

            writer = new IndexWriter(index, new StandardAnalyzer(), create);

            if (!create)
            {                 // delete stale docs
                deleting = true;
                indexDocs(root, index, create);
            }

            indexDocs(root, index, create);       // add new docs

            System.out.println("Optimizing index...");
            writer.optimize();
            writer.close();

            Date end = new Date();

            System.out.print(end.getTime() - start.getTime());
            System.out.println(" total milliseconds");

        }
        catch( Exception e )
        {
            e.printStackTrace();
        }
    }

    /**
     * Walk directory hierarchy in uid order, while keeping uid iterator from
     * existing index in sync.  Mismatches indicate one of: (a) old documents to
     * be deleted; (b) unchanged documents, to be left alone; or (c) new
     * documents, to be indexed.
     *
     * @param file The directory to index.
     * @param index The index to add the file to.
     * @param create A flag telling if we should create the index.
     *
     * @throws Exception If there is any error indexing the directory.
     */
    private void indexDocs(File file, String index, boolean create) throws Exception
    {
        if (!create)
        {                 // incrementally update

            reader = IndexReader.open(index);         // open existing index
            uidIter = reader.terms(new Term("uid", "")); // init uid iterator

            indexDocs(file);

            if (deleting)
            {                 // delete rest of stale docs
                while (uidIter.term() != null && uidIter.term().field().equals( "uid" ) )
                {
                    System.out.println("deleting " +
                    HTMLDocument.uid2url(uidIter.term().text()));
                    reader.deleteDocuments(uidIter.term());
                    uidIter.next();
                }
                deleting = false;
            }

            uidIter.close();                  // close uid iterator
            reader.close();               // close existing index

        }
        else
        {
            indexDocs(file);
        }
    }


    private void indexDocs(File file) throws Exception
    {
        if (file.isDirectory())
        {             // if a directory
            String[] files = file.list();         // list its files
            Arrays.sort(files);           // sort the files
            for (int i = 0; i < files.length; i++)    // recursively index them
            {
                indexDocs(new File(file, files[i]));
            }
        }
        else
        {
            if (uidIter != null)
            {
                String uid = HTMLDocument.uid(file);      // construct uid for doc

                while( uidIter.term() != null &&
                uidIter.term().field().equals( "uid" ) &&
                uidIter.term().text().compareTo(uid) < 0)
                {
                    if (deleting)
                    {             // delete stale docs
                        System.out.println("deleting " +
                        HTMLDocument.uid2url(uidIter.term().text()));
                        reader.deleteDocuments(uidIter.term());
                    }
                    uidIter.next();
                }
                if( uidIter.term() != null &&
                uidIter.term().field().equals( "uid" ) &&
                uidIter.term().text().compareTo(uid) == 0)
                {
                    System.out.println( "Next uid=" +uidIter );
                    uidIter.next();           // keep matching docs
                }
            }
            else
            {
                try
                {
                    addDocument( file );
                }
                catch( IOException e )
                {
                    //catch exception and move onto the next document
                    System.out.println( e.getMessage() );
                }
            }
        }
    }

    private void addDocument( File file ) throws IOException, InterruptedException
    {
        String path = file.getName().toUpperCase();
        Document doc = null;
        //Gee, this would be a great place for a command pattern
        if( path.endsWith(".HTML") || // index .html files
            path.endsWith(".HTM") || // index .htm files
            path.endsWith(".TXT"))
        {
            System.out.println( "Indexing Text document: " + file );
            doc = HTMLDocument.Document(file);
        }
        else if( path.endsWith( ".PDF" ) )
        {
            System.out.println( "Indexing PDF document: " + file );
            doc = LucenePDFDocument.getDocument( file );
        }
        else
        {
            System.out.println( "Skipping " + file );
        }

        if( doc != null )
        {
            writer.addDocument(doc);
        }
    }
}