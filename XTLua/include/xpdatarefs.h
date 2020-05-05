//
//  xpdatarefs.h
//  xlua
//
//  Created by Ben Supnik on 3/20/16.
//
//	Copyright 2016, Laminar Research
//	This source code is licensed under the MIT open source license.
//	See LICENSE.txt for the full terms of the license.

// xTLua
// Modified by Mark Parker on 04/19/2020
#ifndef xpdatarefs_h
#define xpdatarefs_h

#include <string>
#include <vector>
#include "xpcommands.h"
//#include "xpmtdatatypes.h"
using std::string;
class XTCmd
{
    public:
    xlua_cmd * xluaref;
    xlua_cmd_handler_f runFunc;
	int phase;
	float duration;
	void *	m_func_ref;
    bool fire;
    bool start;
    bool stop;
};
struct	xlua_dref;

enum xlua_dref_type {
	xlua_none,
	xlua_number,
	xlua_array,
	xlua_string
};

typedef void (* xlua_dref_notify_f)(xlua_dref * who, void * ref);

xlua_dref *		xlua_find_dref(const char * name);
xlua_dref *		xlua_create_dref(
						const char *				name, 
						xlua_dref_type			type, 
						int						dim, 
						int						writable, 
						xlua_dref_notify_f		func, 
						void *					ref);

xlua_dref_type	xlua_dref_get_type(xlua_dref * who);
int				xlua_dref_get_dim(xlua_dref * who);

double			xlua_dref_get_number(xlua_dref * who);
void			xlua_dref_set_number(xlua_dref * who, double value);
double			xlua_dref_get_array(xlua_dref * who, int n);
void			xlua_dref_set_array(xlua_dref * who, int n, double value);
void			xlua_dref_preUpdate();
void			xlua_dref_postUpdate();
std::vector<XTCmd> get_runQueue();
std::vector<string> get_runMessages();
void xlua_add_callout(string callout);
double xlua_get_simulated_time();
string			xlua_dref_get_string(xlua_dref * who);
void			xlua_dref_set_string(xlua_dref * who, const string& value);

// This attempts to re-establish the name->dref link for any unresolved drefs.  This can be used if we declare
// our dref early and then ANOTHER add-on is loaded that defines it.
void			xlua_relink_all_drefs();

int 			xlua_dref_resolveDREFQueue();
// This deletes EVERY dataref, reclaiming all memory - used once at cleanup.
void			xlua_dref_cleanup();

// Iterates every dataref that Lua knows about and makes sure that they're all valid.
void			xlua_validate_drefs();

#endif /* xpdatarefs_h */
