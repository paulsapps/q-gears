/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-09-22 Tobias Peters <tobias.peters@kreativeffekt.at>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#ifndef __QGearsLGPArchiveSerializer_H__
#define __QGearsLGPArchiveSerializer_H__

#include "QGearsSerializer.h"
#include "QGearsLGPArchive.h"

namespace QGears
{
    class LGPArchiveSerializer : public Serializer
    {
    public:
                        LGPArchiveSerializer();
        virtual        ~LGPArchiveSerializer();

        virtual void    importLGPArchive( Ogre::DataStreamPtr &stream, LGPArchive* pDest );

        enum {
            MAGIC_STRING_LENGTH = 10
          , FILE_NAME_LENGTH    = 20
        };

        typedef LGPArchive::FileEntry FileEntry;
        typedef LGPArchive::FileList  FileList;

    protected:
        virtual void    readFileHeader( Ogre::DataStreamPtr &stream );
        virtual void    readObject( Ogre::DataStreamPtr &stream, FileEntry& file_entry );

        template<typename ValueType> void
        readVector( Ogre::DataStreamPtr &stream, std::vector<ValueType> &pDest, size_t count )
        {
            pDest.clear();
            pDest.reserve( count );
            for( size_t i( count ); i--; )
            {
                ValueType in_tmp;
                readObject( stream, in_tmp );
                pDest.push_back( in_tmp );
            }
        }

    private:
    };
}

#endif // __QGearsLGPArchiveSerializer_H__
