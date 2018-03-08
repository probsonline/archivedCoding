/**
 * Copyright (c) 2003, www.pdfbox.org
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
package org.pdfbox.persistence.util;

/**
 * helper type for faster mapping of bytes to their hex equivalent.
 *
 * @author Michael Traut
 * @version $Revision: 1.4 $
 */
public final class COSHEXTable
{
    /**
     * ASCII byte values for the hex strings.
     */
    public static final byte[][] TABLE =
        {
            "00".getBytes(),
            "01".getBytes(),
            "02".getBytes(),
            "03".getBytes(),
            "04".getBytes(),
            "05".getBytes(),
            "06".getBytes(),
            "07".getBytes(),
            "08".getBytes(),
            "09".getBytes(),
            "0A".getBytes(),
            "0B".getBytes(),
            "0C".getBytes(),
            "0D".getBytes(),
            "0E".getBytes(),
            "0F".getBytes(),
            "10".getBytes(),
            "11".getBytes(),
            "12".getBytes(),
            "13".getBytes(),
            "14".getBytes(),
            "15".getBytes(),
            "16".getBytes(),
            "17".getBytes(),
            "18".getBytes(),
            "19".getBytes(),
            "1A".getBytes(),
            "1B".getBytes(),
            "1C".getBytes(),
            "1D".getBytes(),
            "1E".getBytes(),
            "1F".getBytes(),
            "20".getBytes(),
            "21".getBytes(),
            "22".getBytes(),
            "23".getBytes(),
            "24".getBytes(),
            "25".getBytes(),
            "26".getBytes(),
            "27".getBytes(),
            "28".getBytes(),
            "29".getBytes(),
            "2A".getBytes(),
            "2B".getBytes(),
            "2C".getBytes(),
            "2D".getBytes(),
            "2E".getBytes(),
            "2F".getBytes(),
            "30".getBytes(),
            "31".getBytes(),
            "32".getBytes(),
            "33".getBytes(),
            "34".getBytes(),
            "35".getBytes(),
            "36".getBytes(),
            "37".getBytes(),
            "38".getBytes(),
            "39".getBytes(),
            "3A".getBytes(),
            "3B".getBytes(),
            "3C".getBytes(),
            "3D".getBytes(),
            "3E".getBytes(),
            "3F".getBytes(),
            "40".getBytes(),
            "41".getBytes(),
            "42".getBytes(),
            "43".getBytes(),
            "44".getBytes(),
            "45".getBytes(),
            "46".getBytes(),
            "47".getBytes(),
            "48".getBytes(),
            "49".getBytes(),
            "4A".getBytes(),
            "4B".getBytes(),
            "4C".getBytes(),
            "4D".getBytes(),
            "4E".getBytes(),
            "4F".getBytes(),
            "50".getBytes(),
            "51".getBytes(),
            "52".getBytes(),
            "53".getBytes(),
            "54".getBytes(),
            "55".getBytes(),
            "56".getBytes(),
            "57".getBytes(),
            "58".getBytes(),
            "59".getBytes(),
            "5A".getBytes(),
            "5B".getBytes(),
            "5C".getBytes(),
            "5D".getBytes(),
            "5E".getBytes(),
            "5F".getBytes(),
            "60".getBytes(),
            "61".getBytes(),
            "62".getBytes(),
            "63".getBytes(),
            "64".getBytes(),
            "65".getBytes(),
            "66".getBytes(),
            "67".getBytes(),
            "68".getBytes(),
            "69".getBytes(),
            "6A".getBytes(),
            "6B".getBytes(),
            "6C".getBytes(),
            "6D".getBytes(),
            "6E".getBytes(),
            "6F".getBytes(),
            "70".getBytes(),
            "71".getBytes(),
            "72".getBytes(),
            "73".getBytes(),
            "74".getBytes(),
            "75".getBytes(),
            "76".getBytes(),
            "77".getBytes(),
            "78".getBytes(),
            "79".getBytes(),
            "7A".getBytes(),
            "7B".getBytes(),
            "7C".getBytes(),
            "7D".getBytes(),
            "7E".getBytes(),
            "7F".getBytes(),
            "80".getBytes(),
            "81".getBytes(),
            "82".getBytes(),
            "83".getBytes(),
            "84".getBytes(),
            "85".getBytes(),
            "86".getBytes(),
            "87".getBytes(),
            "88".getBytes(),
            "89".getBytes(),
            "8A".getBytes(),
            "8B".getBytes(),
            "8C".getBytes(),
            "8D".getBytes(),
            "8E".getBytes(),
            "8F".getBytes(),
            "90".getBytes(),
            "91".getBytes(),
            "92".getBytes(),
            "93".getBytes(),
            "94".getBytes(),
            "95".getBytes(),
            "96".getBytes(),
            "97".getBytes(),
            "98".getBytes(),
            "99".getBytes(),
            "9A".getBytes(),
            "9B".getBytes(),
            "9C".getBytes(),
            "9D".getBytes(),
            "9E".getBytes(),
            "9F".getBytes(),
            "A0".getBytes(),
            "A1".getBytes(),
            "A2".getBytes(),
            "A3".getBytes(),
            "A4".getBytes(),
            "A5".getBytes(),
            "A6".getBytes(),
            "A7".getBytes(),
            "A8".getBytes(),
            "A9".getBytes(),
            "AA".getBytes(),
            "AB".getBytes(),
            "AC".getBytes(),
            "AD".getBytes(),
            "AE".getBytes(),
            "AF".getBytes(),
            "B0".getBytes(),
            "B1".getBytes(),
            "B2".getBytes(),
            "B3".getBytes(),
            "B4".getBytes(),
            "B5".getBytes(),
            "B6".getBytes(),
            "B7".getBytes(),
            "B8".getBytes(),
            "B9".getBytes(),
            "BA".getBytes(),
            "BB".getBytes(),
            "BC".getBytes(),
            "BD".getBytes(),
            "BE".getBytes(),
            "BF".getBytes(),
            "C0".getBytes(),
            "C1".getBytes(),
            "C2".getBytes(),
            "C3".getBytes(),
            "C4".getBytes(),
            "C5".getBytes(),
            "C6".getBytes(),
            "C7".getBytes(),
            "C8".getBytes(),
            "C9".getBytes(),
            "CA".getBytes(),
            "CB".getBytes(),
            "CC".getBytes(),
            "CD".getBytes(),
            "CE".getBytes(),
            "CF".getBytes(),
            "D0".getBytes(),
            "D1".getBytes(),
            "D2".getBytes(),
            "D3".getBytes(),
            "D4".getBytes(),
            "D5".getBytes(),
            "D6".getBytes(),
            "D7".getBytes(),
            "D8".getBytes(),
            "D9".getBytes(),
            "DA".getBytes(),
            "DB".getBytes(),
            "DC".getBytes(),
            "DD".getBytes(),
            "DE".getBytes(),
            "DF".getBytes(),
            "E0".getBytes(),
            "E1".getBytes(),
            "E2".getBytes(),
            "E3".getBytes(),
            "E4".getBytes(),
            "E5".getBytes(),
            "E6".getBytes(),
            "E7".getBytes(),
            "E8".getBytes(),
            "E9".getBytes(),
            "EA".getBytes(),
            "EB".getBytes(),
            "EC".getBytes(),
            "ED".getBytes(),
            "EE".getBytes(),
            "EF".getBytes(),
            "F0".getBytes(),
            "F1".getBytes(),
            "F2".getBytes(),
            "F3".getBytes(),
            "F4".getBytes(),
            "F5".getBytes(),
            "F6".getBytes(),
            "F7".getBytes(),
            "F8".getBytes(),
            "F9".getBytes(),
            "FA".getBytes(),
            "FB".getBytes(),
            "FC".getBytes(),
            "FD".getBytes(),
            "FE".getBytes(),
            "FF".getBytes()
            };

    /**
     * ASCII byte values for the hex strings.
     */
    public static final String[] HEX_TABLE = 
        {
            "00",
            "01",
            "02",
            "03",
            "04",
            "05",
            "06",
            "07",
            "08",
            "09",
            "0A",
            "0B",
            "0C",
            "0D",
            "0E",
            "0F",
            "10",
            "11",
            "12",
            "13",
            "14",
            "15",
            "16",
            "17",
            "18",
            "19",
            "1A",
            "1B",
            "1C",
            "1D",
            "1E",
            "1F",
            "20",
            "21",
            "22",
            "23",
            "24",
            "25",
            "26",
            "27",
            "28",
            "29",
            "2A",
            "2B",
            "2C",
            "2D",
            "2E",
            "2F",
            "30",
            "31",
            "32",
            "33",
            "34",
            "35",
            "36",
            "37",
            "38",
            "39",
            "3A",
            "3B",
            "3C",
            "3D",
            "3E",
            "3F",
            "40",
            "41",
            "42",
            "43",
            "44",
            "45",
            "46",
            "47",
            "48",
            "49",
            "4A",
            "4B",
            "4C",
            "4D",
            "4E",
            "4F",
            "50",
            "51",
            "52",
            "53",
            "54",
            "55",
            "56",
            "57",
            "58",
            "59",
            "5A",
            "5B",
            "5C",
            "5D",
            "5E",
            "5F",
            "60",
            "61",
            "62",
            "63",
            "64",
            "65",
            "66",
            "67",
            "68",
            "69",
            "6A",
            "6B",
            "6C",
            "6D",
            "6E",
            "6F",
            "70",
            "71",
            "72",
            "73",
            "74",
            "75",
            "76",
            "77",
            "78",
            "79",
            "7A",
            "7B",
            "7C",
            "7D",
            "7E",
            "7F",
            "80",
            "81",
            "82",
            "83",
            "84",
            "85",
            "86",
            "87",
            "88",
            "89",
            "8A",
            "8B",
            "8C",
            "8D",
            "8E",
            "8F",
            "90",
            "91",
            "92",
            "93",
            "94",
            "95",
            "96",
            "97",
            "98",
            "99",
            "9A",
            "9B",
            "9C",
            "9D",
            "9E",
            "9F",
            "A0",
            "A1",
            "A2",
            "A3",
            "A4",
            "A5",
            "A6",
            "A7",
            "A8",
            "A9",
            "AA",
            "AB",
            "AC",
            "AD",
            "AE",
            "AF",
            "B0",
            "B1",
            "B2",
            "B3",
            "B4",
            "B5",
            "B6",
            "B7",
            "B8",
            "B9",
            "BA",
            "BB",
            "BC",
            "BD",
            "BE",
            "BF",
            "C0",
            "C1",
            "C2",
            "C3",
            "C4",
            "C5",
            "C6",
            "C7",
            "C8",
            "C9",
            "CA",
            "CB",
            "CC",
            "CD",
            "CE",
            "CF",
            "D0",
            "D1",
            "D2",
            "D3",
            "D4",
            "D5",
            "D6",
            "D7",
            "D8",
            "D9",
            "DA",
            "DB",
            "DC",
            "DD",
            "DE",
            "DF",
            "E0",
            "E1",
            "E2",
            "E3",
            "E4",
            "E5",
            "E6",
            "E7",
            "E8",
            "E9",
            "EA",
            "EB",
            "EC",
            "ED",
            "EE",
            "EF",
            "F0",
            "F1",
            "F2",
            "F3",
            "F4",
            "F5",
            "F6",
            "F7",
            "F8",
            "F9",
            "FA",
            "FB",
            "FC",
            "FD",
            "FE",
            "FF"
            };
}