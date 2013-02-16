/*
 * Copyright 2011 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_FOO_API_H
#define INCLUDED_FOO_API_H
#include <time.h>
//#include <pmt.h>

template <class T>
T min_first (T *n, T *m) 
{
  /* order and return the minimum */ 
  int swap; 
  if (*n > *m) {
    swap = *n;
    *n = *m;
    *m = swap; 
  } return *n; 
}

namespace rmg 
{

  const int AVG_CT = 1024;
  const int PEAK_LENGTH = 6; 

  typedef struct {

    time_t timestamp;
    int ct; 
    double avg; 
    
    /* some useful parameters, such as center freq, data count, etc. */


  } param_t; 

}

#include <gruel/attributes.h>

#ifdef gnuradio_foo_EXPORTS
#  define FOO_API __GR_ATTR_EXPORT
#else
#  define FOO_API __GR_ATTR_IMPORT
#endif

#endif /* INCLUDED_FOO_API_H */
