XTLua
====

XTLua is a modification of XLua which runs lua - specifically before_physics and after_physics lua functions in a worker thread aysnchronously to X-Plane.

The goal is to facilitate more complex Lua calcuations without impacting the X-Plane frame rate. The Lua bindings of XLua have been replaced with xtluaDefs in xpdatarefs.cpp which synchronize the current variable states of XTLua with X-Plane once each flight model frame.

Release Notes
-----------------
2.0.2a4 - 06/27/2020
feature complete

0.0.5b1 -  05/08/2020
rewrite XTLuaChar

0.0.2b1 -  04/19/2020

Initial Release
XLua
====

XLua is a very simple Lua adapter plugin for X-Plane. It allows authors to create and modify commands and add create new datarefs for X-Plane aircraft.

XLua's functionality is in its core similar to Gizmo, SASL and FlyWithLua, but it is much smaller and has only a tiny fraction of these other plugn's functionality. The goals of XLua are simplicity, ease of use and to be light weight and minimal. XLua is meant to provide a small amount of "glue" to aircraft authors to connect art assets to the simulator itself.

XLua is developed internally by Laminar Research and is intended to help our internal art team, but anyone is free to use it, modify it, hack it, etc.; it is licensed under the MIT/X11 license and is thus Free and Open Source Software.

XLua is **not** meant to be an "official" Lua plugin for X-Plane, and it definitely does not replace any of the existing Lua plugins, all of which have significantly more features than XLua itself.

Release Notes
-----------------

1.0.0r1 - 11/6/2017

Bug fixes:
 * Support for unicode install paths on Windows.
 * Timing source is now sim time and not user interface time. Fixes scripts breaking on pause.
 * Debug logging of missing datarefs.
 * Full back-trace of uncaught Lua exceptions.

1.0.0b1 - 11/26/16

Initial Release
