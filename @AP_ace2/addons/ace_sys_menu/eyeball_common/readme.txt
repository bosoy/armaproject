================================================================================
ArmA Dialog Template - v1.1
================================================================================

This file is a draft and will not be completed for v1.0, but will be updated in 
a future release, or check the BIS forums for extra info.

--------------------------------------------------------------------------------
FEATURES
--------------------------------------------------------------------------------
- A base dialog template (which you can modify to create a new one fairly easily)
- A popup menu system (for dialogs and MapClicks). You can avoid dialog code totally by using this.
- A basic Yes/No dialog
- A debug output dialog
(Planning a few more base dialogs in future)
- Base control classes separated into separate files - (hopefully) no need to edit it, in general
- Uses full inheritence, minimising the code you work with significantly
- A base color scheme (saves fussing with colors for all controls & dialogs)
- Hundreds of color constants
- Dialog specific functions script (only 3 functions so far, but I hope to add to it).

--------------------------------------------------------------------------------
PURPOSE
--------------------------------------------------------------------------------

- It includes a recommended structure for inheritance. This reduces the overall code required significantly and makes it easier to read and interpret.
- It separates the standard #define constants and class definitions into separate files.
- It provides extra #define constants to replace many common literals.
- Standardise default sizing, positioning - controlled by several base constants, to allow you to treat coordinates as columns & rows.
- Standardise color scheme and color names

Functionality:
--------------
- A base dialog template
- A popup menu system
- A Yes/No dialog
- A debug output dialog

--------------------------------------------------------------------------------
USAGE
--------------------------------------------------------------------------------
To be added in a future release, or check the BIS forum.

--------------------------------------------------------------------------------
MODIFYING THE FILES
--------------------------------------------------------------------------------

Note! If you need to do any modifications to the files included with your 
mission (especially those in \Dialogs\Common), please mark the modified files as 
modified by you to avoid confusing them with the originals.

Eg:
Modified by: MyName

--------------------------------------------------------------------------------
VERSION HISTORY
--------------------------------------------------------------------------------

Version | Date | Notes

1.0 | 20 May 2007 | First release
1.1 | 31 May 2007 | PopupMenu functionality, Debug dialog added.

--------------------------------------------------------------------------------
CREDITS
--------------------------------------------------------------------------------

Contributors: Dr_Eyeball, mi2slow & Vienna (quickmap.hpp), BIKI

--------------------------------------------------------------------------------
LEGAL DISCLAIMER
--------------------------------------------------------------------------------

The Software is distributed without any warranty; without even the implied 
warranty of merchantability or fitness for a particular purpose. Use of the 
Software (in whole or in part) is entirely at your own risk.

--------------------------------------------------------------------------------
DISTRIBUTING SIMULATION CONTENT CREATED WITH THE SOFTWARE
--------------------------------------------------------------------------------

Please note that you do NOT require permission from The Contributors to 
distribute simulation content (e.g. missions) created with the Software.
