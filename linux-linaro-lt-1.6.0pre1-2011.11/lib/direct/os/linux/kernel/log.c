/*
   (c) Copyright 2001-2008  The world wide DirectFB Open Source Community (directfb.org)
   (c) Copyright 2000-2004  Convergence (integrated media) GmbH

   All rights reserved.

   Written by Denis Oliver Kropp <dok@directfb.org>,
              Andreas Hundt <andi@fischlustig.de>,
              Sven Neumann <neo@directfb.org>,
              Ville Syrjälä <syrjala@sci.fi> and
              Claudio Ciccani <klan@users.sf.net>.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the
   Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#include <config.h>

#include <direct/log.h>
#include <direct/messages.h>

/**********************************************************************************************************************/

__attribute__((no_instrument_function))
static DirectResult
printk_log_write( DirectLog  *log,
                  const char *buffer,
                  size_t      bytes )
{
     printk( KERN_DEBUG "%*s", (int) bytes, buffer );

     return DR_OK;
}

/**********************************************************************************************************************/

__attribute__((no_instrument_function))
DirectResult
direct_log_init( DirectLog  *log,
                 const char *param )
{
     switch (log->type) {
          case DLT_STDERR:
               break;

          default:
               D_UNIMPLEMENTED();
               break;
     }

     log->write = printk_log_write;

     return DR_OK;
}

DirectResult
direct_log_deinit( DirectLog *log )
{
     return DR_OK;
}

