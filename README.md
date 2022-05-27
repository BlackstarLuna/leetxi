leetxi
======

pre-alpha
=========

some minor adjustments to the structure were made
to allow for a polite installer, and to add
proper error handling.

prior to a proper alpha release for testing
i will be adding a pkgbuild, testing upon
a steamdeck vm, and focusing on arch
based distrubutions.

after, there will be work done
on a debian,fedora,ubuntu
installer.  though that will take
some effort to track down dependencies
so it is lower priority at this time.

There also, will be a second installer
as to seperate the main application
from the cosmetic ehancements
as to not overburden lower end hardware.

==overview==
============

taking up this old project prior known
as mounter2, and repurposing it as
it is dead in the water due to lack of
need for isos in todays gaming world

it is being repurposed as a linux
complete xi launcher for wingsxi
as such it can be adjusted
and repackaged for base ashita
yet given its dependencies
on reshade and dgvoodoo2
it would in its current form
need to be rebuilt depending 
on players choice in server.

As such, the utilty to launch
Ashita will also be packaged 
seperately from the overall
installation.

----------------------------------------

what does this do?
==================

this project will use a 64 bit
prefix to launch ffxi via Ashita's
injector allowing for the use of addons
as well as heavy graphical enchancements
using DAT swaps, dgvoodoo ehancements
and reshade.  providing an enjoyable
and aesthetically pleasing xi experience
on linux based systems.

how does it do this?
====================

provding a gtk frontend to simplify
the experience we edit the neccessary
files in the ashita folder, allowing
for graphical configuration of Ashita
addons, plugins and the like
prior to executing the injector.

what's next?
============

it would be most desirable
to have this work easily across
all xi servers.  As such it is in
the scope of this project to provide
in time the ability to install
a client as well as launch Ashita
be that retail, or any number
of present and future xi clients.

Dependencies
============

this project relys on:
wine-staging-7.7 both 32 and 64bit
vulkan
d3dcompiler_47
dxvk and vkd3d

Written in C

----------------------------------------
old project info:
----------------------------------------
mounter2
========

----------------------------------------

mounter2 is desgined to make mounting iso files
much simpler. :-D


