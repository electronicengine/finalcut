/***********************************************************************
* fsize.cpp - Height and width of a two-dimensional surface            *
*                                                                      *
* This file is part of the Final Cut widget toolkit                    *
*                                                                      *
* Copyright 2014-2019 Markus Gans                                      *
*                                                                      *
* The Final Cut is free software; you can redistribute it and/or       *
* modify it under the terms of the GNU Lesser General Public License   *
* as published by the Free Software Foundation; either version 3 of    *
* the License, or (at your option) any later version.                  *
*                                                                      *
* The Final Cut is distributed in the hope that it will be useful,     *
* but WITHOUT ANY WARRANTY; without even the implied warranty of       *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        *
* GNU Lesser General Public License for more details.                  *
*                                                                      *
* You should have received a copy of the GNU Lesser General Public     *
* License along with this program.  If not, see                        *
* <http://www.gnu.org/licenses/>.                                      *
***********************************************************************/

#include "final/fsize.h"

namespace finalcut
{

//----------------------------------------------------------------------
// class FSize
//----------------------------------------------------------------------

FSize::~FSize()  // destructor
{ }

// public methods of FSize
//----------------------------------------------------------------------
FSize& FSize::operator = (const FSize& s)
{
  width = s.width;
  height = s.height;
  return *this;
}

//----------------------------------------------------------------------
FSize& FSize::operator += (const FSize& s)
{
  constexpr std::size_t max = std::numeric_limits<std::size_t>::max();
  width = ( width < max - s.width) ? width + s.width : max;
  height = ( height < max - s.height) ? height + s.height : max;
  return *this;
}

//----------------------------------------------------------------------
FSize& FSize::operator -= (const FSize& s)
{
  width = ( width >= s.width ) ? width - s.width : 0;
  height = ( height >= s.height ) ? height - s.height : 0;
  return *this;
}

//----------------------------------------------------------------------
void FSize::setWidth (std::size_t w)
{
  width = w;
}

//----------------------------------------------------------------------
void FSize::setHeight (std::size_t h)
{
  height = h;
}

//----------------------------------------------------------------------
void FSize::setSize (FSize s)
{
  width = s.width;
  height = s.height;
}

//----------------------------------------------------------------------
void FSize::setSize (std::size_t w, std::size_t h)
{
  width = w;
  height = h;
}

//----------------------------------------------------------------------
bool FSize::isEmpty() const
{
  return width == 0 && height == 0;
}

//----------------------------------------------------------------------
std::ostream& operator << (std::ostream& outstr, const FSize& s)
{
  outstr << s.width << " " << s.height;
  return outstr;
}

//----------------------------------------------------------------------
std::istream& operator >> (std::istream& instr, FSize& s)
{
  std::size_t w, h;
  instr >> w;
  instr >> h;
  s.setSize (w, h);
  return instr;
}

}  // namespace finalcut
