/*
Open Asset Import Library (assimp)
----------------------------------------------------------------------

Copyright (c) 2006-2022, assimp team

All rights reserved.

Redistribution and use of this software in source and binary forms,
with or without modification, are permitted provided that the
following conditions are met:

* Redistributions of source code must retain the above
  copyright notice, this list of conditions and the
  following disclaimer.

* Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the
  following disclaimer in the documentation and/or other
  materials provided with the distribution.

* Neither the name of the assimp team, nor the names of its
  contributors may be used to endorse or promote products
  derived from this software without specific prior
  written permission of the assimp team.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------
*/

#pragma once

#include <vector>

namespace Assimp {

/// @brief This class provides the decompression of zlib-compressed data.
class Compression {
public:
    enum class Format {
        Binary = 0,
        ASCII,

        NumFormats,
        InvalidFormat
    };
    /// @brief  The class constructor.
    Compression();

    ///	@brief  The class destructor.
    ~Compression();

    /// @brief  Will open the access to the compression.
    /// @return true if close was successful, false if not.
    bool open(Format format);

    /// @brief  Will return the open state.
    /// @return true if the access is opened, false if not.
    bool isOpen() const;

    /// @brief  Will close the decompress access.
    /// @return true if close was successful, false if not.
    bool close();

    /// @brief Will decompress the data buffer.
    /// @param[in] data         The data to decompress
    /// @param[in] in           The size of the data.
    /// @param[out uncompressed A std::vector containing the decompressed data.
    size_t decompress(const void *data, size_t in, std::vector<char> &uncompressed);

    size_t decompressBlock(const void *data, size_t in, char *out, size_t availableOut);

private:
    struct impl;
    impl *mImpl;
};

} // namespace Assimp
