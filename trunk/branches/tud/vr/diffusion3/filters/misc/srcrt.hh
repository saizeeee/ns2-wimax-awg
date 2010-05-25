//
// srcrt.hh       : Source Route Filter Include File
// author         : Fabio Silva
//
// Copyright (C) 2000-2002 by the Unversity of Southern California
// $Id: srcrt.hh,v 1.1.1.1 2008/04/11 18:40:30 rouil Exp $
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License,
// version 2, as published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
//
// Linking this file statically or dynamically with other modules is making
// a combined work based on this file.  Thus, the terms and conditions of
// the GNU General Public License cover the whole combination.
//
// In addition, as a special exception, the copyright holders of this file
// give you permission to combine this file with free software programs or
// libraries that are released under the GNU LGPL and with code included in
// the standard release of ns-2 under the Apache 2.0 license or under
// otherwise-compatible licenses with advertising requirements (or modified
// versions of such code, with unchanged license).  You may copy and
// distribute such a system following the terms of the GNU GPL for this
// file and the licenses of the other code concerned, provided that you
// include the source code of that other code when and as the GNU GPL
// requires distribution of source code.
//
// Note that people who make modified versions of this file are not
// obligated to grant this special exception for their modified versions;
// it is their choice whether to do so.  The GNU General Public License
// gives permission to release a modified version without this exception;
// this exception also makes it possible to release a modified version
// which carries forward this exception.

#ifndef SRCRT_HH
#define SRCRT_HH

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif // HAVE_CONFIG_H

#ifdef NS_DIFFUSION
#include "diffagent.h"
#endif // NS_DIFFUSION

#include "diffapp.hh"

#define SRCRT_FILTER_PRIORITY 90

class SrcRtFilter;

class SrcRtFilterReceive : public FilterCallback {
public:
  SrcRtFilterReceive(SrcRtFilter *app) : app_(app) {};
  void recv(Message *msg, handle h);

  SrcRtFilter *app_;
};

class SrcRtFilter : public DiffApp {
public:
#ifdef NS_DIFFUSION
  SrcRtFilter();
  int command(int argc, const char*const* argv);
#else
  SrcRtFilter(int argc, char **argv);
#endif // NS_DIFFUSION

  void run();
  void recv(Message *msg, handle h);

protected:
  // General Variables
  handle filter_handle_;

  // Receive Callback for the filter
  SrcRtFilterReceive *filter_callback_;

  // Filter interface
  handle setupFilter();

  // Message Processing
  Message * ProcessMessage(Message *msg);
};
#endif // !SRCRT_HH
