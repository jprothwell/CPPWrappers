/*
*   Copyright © Ben D.
*   dbapps2@gmail.com
*
*   This is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef BUFFERED_INPUT_H__
#define BUFFERED_INPUT_H__

#include <Fs/AbstractBufferIO.h>

#include <string.h>

/**
 * @brief Allows read from file
 */
class BufferedInput: public AbstractBufferIO
{

    public:

        /**
         * @brief Construcotr
         * @param f the File object in which we will read
         */
        BufferedInput(File& f);

        /**
         * @brief Destructor
         */
        ~BufferedInput();

        /**
         * @brief reads a whole line from the file. If the line does not end with '\n', readLine will read the whole line from the current seek to the end
         * @return an empty string if error occured (EOF, file not found ..) or the line read
         * You can check with the eof() function to see if the EOF is reached and with the AbstractBufferIO::getBufferStatus() method to see the error type
         * @see AbstractBufferIO::Status
         * @see eof()
         */
        string readLine();

        /**
         * @brief reads a whole word from the file. If there are no ' ', readWord will read the whole file from the current seek to the end
         * @return an empty string if error occured (EOF, file not found ..) or the word read
         * You can check with the eof() function to see if the EOF is reached and with the AbstractBufferIO::getBufferStatus() method to see the error type
         * @see AbstractBufferIO::Status
         * @see eof()
         */
        string readWord();

        /**
         * @brief read at most nb character from the file
         * @return an empty string if an error occured or the characters read
         * You can check with the eof() function to see if the EOF is reached and with the AbstractBufferIO::getBufferStatus() method to see the error type
         * @see AbstractBufferIO::Status
         * @see eof()
         */
        string read(int nb);

        /**
         * @brief checks is the EOF is reached
         * @return true if EOF, false otherwise
         */
        bool eof();

        /**
         * @brief closes the file
         * @return void (should not fail)
         * errors can be checked with the AbstractBufferIO::getBufferStatus() method to see the error type
         */
        void close();

        /**
         * @brief reads a word and puts it in data
         * The error status can be checked with the AbstractBufferIO::getBufferStatus() method
         */
        BufferedInput& operator >>(string& data);

        /**
         * @brief reads a word and puts it in ch
         * The error status can be checked with the AbstractBufferIO::getBufferStatus() method
         */
        BufferedInput& operator >>(char* ch);

        /**
         * @brief reads sizeof(int) characters and puts it in the int
         * The error status can be checked with the AbstractBufferIO::getBufferStatus() method
         */
        BufferedInput& operator >>(int& i);

        /**
         * @brief reads 1 character and puts it in c
         * The error status can be checked with the AbstractBufferIO::getBufferStatus() method
         */
        BufferedInput& operator >>(char& c);

        /**
         * @brief reads sizeof(float) characters and puts it in f
         * The error status can be checked with the AbstractBufferIO::getBufferStatus() method
         */
        BufferedInput& operator >>(float& f);

        /**
         * @brief reads sizeof(short) character and puts it in s
         * The error status can be checked with the AbstractBufferIO::getBufferStatus() method
         */
        BufferedInput& operator >>(short& s);

        /**
         * @brief reads sizeof(long) characters and puts it in l
         * The error status can be checked with the AbstractBufferIO::getBufferStatus() method
         */
        BufferedInput& operator >>(long& l);

    private:
        File m_file;

};

#endif
