## LinCity-NG 2.14.0

date: 2025-07-04

###### Gameplay
- Fixed a bug that allowed uncompleted monuments to be bulldozed.
- Improved terrain/ecology generation algorithms.

###### User Interface
- Fixed grid-lines appearing on the map.
- Fixed duplicate click events in the new-game menu.
- Added warning dialogs when a construction cannot be built.
- Reworded most in-game pop-up dialogs.
- Fixed the "map size" configuration option so it no longer resets to 100 when
  loading a scenario.
- Added `--config`, `--app-data`, and `--user-data` command-line options for
  specifying custom paths.
- Removed support for restarting the game automatically. This means the user
  must restart the game manually if they change the language setting.

###### Internal
- Removed PhysFS library dependency in favor of C++17 Filesystem library.
- Added cfgpath library for detecting config and user data locations.
- Added [libfmt](https://fmt.dev/latest/index.html) library dependency for
  formatting translatable strings.
- Changed SDL2 dependency minimum version from 2.0.0 to 2.0.18.
- Removed SDL2_gfx library dependency.
- Changed the default `CMAKE_BUILD_TYPE` to **Release** instead of being
  system-dependent.
- Changed detection of app data location to use `CMAKE_INSTALL_PREFIX`. Note:
  `--install-prefix` may need to be specified at configure time with the
  expected install location; otherwise, the default app data directory will be
  incorrect.
- Added `appDataDir` and `userDataDir` config options for storing non-standard
  app data and user data locations.
- Changed format and location of config file.
- Added hardware-accelerated rendering in SDL video mode.
- Added hardware-accelerated blitting.
- Removed GL video mode.
- Fixed two memory leaks from paragraph textures.
- Improved separation between front-end and back-end logic.
- Removed many singletons from the code.
- Removed `error.h` dependency for Unix-based systems. This improves portability
  as not all Unix-based systems have the `error.h` header.

###### Documentation / Translation
- Fixed translatable phrases appearing as fragments to translators due to string
  concatenation.
- Added documentation about the CMAKE_BUILD_TYPE options to the readme.
- Added explanation of very-negative residence desirability to the help page.


## LinCity-NG 2.13.1

date: 2025-02-15

###### User Interface
- Fixed popup dialog text not showing.
- Fixed input lag in main menu.

###### Internal
- Fixed random crashing on Windows caused by a bad string termination.
- Fixed segfault when loading communes from a saved game.
- Fixed freeze on launch.
- Fixed freeze when starting a game.
- Fixed segfault and dangling thread when quitting the game in debug mode.


## LinCity-NG 2.13.0 [SECURITY]

date: 2025-01-26

###### Gameplay
- Fixed rocket pads resetting after save-load cycle.

###### User Interface
- Fixed the camera position when starting a game.
- Added popup dialog for game load errors
- Fixed lag and high CPU utilization in menus.
- Changed dialogs to be not resizable by default.
- Removed construction ID numbers.

###### Internal
- [SECURITY] Fixed a heap overflow in game loading.
- Changed the load/save format. (Games saved with previous versions of
  LinCity-NG are incompatible with the current version and vise-versa.)
- Added a script to convert games from the load/save format of version 2.12.x.
- Added libxml++ dependency for load/save parsing.
- Changed starting scenarios to current load/save format.
- Fixed an issue where games may not load correctly on a different platform than
  the one used for saving.
- Changed the C++ standard from C++11 to C++17.
- Added BetaTest and DebugOpt build configurations.
- Removed ~/.lincity-ng from the search path.

###### Documentation / Translation
- Added a contributing guide.
- Added Hungarian translation for GUI and source strings.
- Fixed formatting on information tabs help page.


## LinCity-NG 2.12.0

date: 2024-11-13

###### Gameplay
- Fixed tech requirement enforcement after tech decrease.

###### User Interface
- Changed rocket icon.
- Fixed duplicate/erroneous invention messages.
- Changed the left- and right- click actions for button panel menus. Now,
  left-click toggles the drawer, and right-click activates the shown tool.
- Fixed button-panel buttons displaying incorrect checked/unchecked/hovered
  state.
- Removed 'quickness' parameter from command-line options and config file.

###### Internal
- Deprecated binary load/save format.
- Deprecated old load/save format.
- Deprecated seed-compression load/save mode.
- Converted starting scenarios to current save format.
- Fixed simulation tick on load when paused.
- Fixed segfault while bulldozing.
- Removed many unused files from install.
- Changed GUI callbacks to use C++ std::function.
- Added a class to manage radio buttons.
- Cleaned up (fully rewrote) the button-panel internals.
- Moved button-panel tool definitions from the source code to the GUI XML.
- Changed PhysFS-SDL2 glue layer from custom implementation to physfswrops.
- Fixed repeated git merge conflicts in CHANGELOG.md.

###### Documentation / Translation
- Updated the controls help page.


## LinCity-NG 2.11.2 [SECURITY]

date: 2024-09-26 <br/>
tag: lincity-ng-2.11.2

###### Gameplay
- Fixed sustainability not resetting when dumping on a tip.
- Fixed tech-based output for farms and power stations.

###### User Interface
- Fixed cars not spawning on track/road/rail.

###### Internal
- [SECURITY] Fixed a heap overflow in game loading.
- Fixed an error raised by CPack for missing README.md file.
- Removed unneeded image source files from install.

###### Documentation / Translation
- Fixed the tip icon in help pages.
- Added Italian translation for .desktop file.
- Fixed several inconsistencies in translated help pages.
- Added a script for detecting inconsistencies in translated help pages.
- Fixed a typo in the rocket help page.


## LinCity-NG 2.11.1

date: 2024-07-19 <br/>
tag: lincity-ng-2.11.1 <br/>
git: f42e76c3

###### Internal
- Fixed crash when loading randomized scenario.
- Fixed a compile-time error in src/gui/event.cpp when building with
  SDL <= 2.26.0.
- Fixed a compile-time error in src/lincity/xmlloadsave.cpp when building with
  older g++ version.
- Fixed parsing boolean from XML save file.
- Fixed blacksmiths sometimes skipping monthly update. This was causing
  blacksmiths to display more than 100% busy.


## LinCity NG 2.11.0

date: 2024-06-24 <br/>
tag: lincity-ng-2.11.0 <br/>
git: afaede3d

###### Gameplay
- Nerfed ports by randomly disabling import/export.
- Reduced coal tax by 40%.

###### User Interface
- Renamed MWh and kWh commodities to "high-voltage power" and
  "low-voltage power" respectively with short names "hi-volt" and "lo-volt".
- Renamed "jobs" commodity to "labor".
- Fixed failure to load sound effects.
- Made in-game windows and dialogs resizable by dragging the edges/corners.
- Changed date format in status bar.

###### Internal
- Fixed portability for Windows.
- Added support for cross-compiling from Linux to Windows with MinGW-w64. (Now
  Windows binaries can be included in releases.)
- Fixed "Invalid ExtraFrames" warning caused by waste fires.
- Fixed some warnings re. excessive production/consumption.
- Added error checking for loading sound effects.
- Removed messages.pot generation from normal build. This removes the gettest
  build dependency except for translators. Translators must now generate the
  messages.pot file with a separate build step.
- Fixed missing git describe in package versions that are generated with CPack.
- Fixed extraneous link libraries.
- Added Include What You Use as a build step, and cleaned up includes.
- Improved handling of waste fires, so they are less bug prone.
- Refactored lintypes.cpp/hpp and moved some symbols to other files.
- Switched internal libraries from object to static type.
- Cleaned up target link libraries.
- Add fatal check for null in getGameView.
- Fixed handling of window size in fullscreen mode.
- Fixed some typos.

###### Documentation
- Added production/consumption formulas for each module to help pages.

###### Known Issues
- Some translations may be outdated since renaming commodities.
- Production/Consumption formulas do not exist in translated help pages.
- Requires SDL >= 2.26.0
- Crashes when the first game loaded is a new randomized scenario.
- Blacksmiths may display more than 100% busy.


## LinCity NG 2.10.2

date: 2024-04-19 <br/>
tag: lincity-ng-2.10.2 <br/>
git: a6101294

###### User Interface:
- Fixed a bug in installation/packaging which prevented creation of certain GUI
  components especially dialogs.


## LinCity NG 2.10.1

date: 2024-03-16 <br/>
tag: lincity-ng-2.10.1 <br/>
git: 3b8c58bf

###### Internal
- Fixed an unsafe memory write which could cause the game to crash.
- Added 'git' to the list of build dependencies.

###### Documentation / Translation
- Added a note in the readme to warn users of different build instructions for
  different versions of LinCity NG.


## LinCity NG 2.10.0

date: 2024-03-08 <br/>
tag: lincity-ng-2.10.0 <br/>
git: f03cbe18

###### Gameplay
- Fixed the amount of swing jobs created by health cover. You may now find that
  you need fewer residences and/or more jobs demand in your economy.
- Changed the effect of swing jobs. Now jobs production at residences scales
  down as inventory increases. This should make employment feel more stable and
  make it easier to strike a balance in employment. The amount of the production
  decrease is dependent on "swing" jobs, so sports cover and health cover
  increase the effect. The previous method using a "swingometer" has been
  abandoned.
- Fixed evacuation logic to avoid a construction getting negative inventory.
- Added water to the market trade dialog.

###### User Interface
- Fixed jumpy and laggy scrolling near the map edge.
- Fixed a bug where the shift key (used to increase scroll speed) was
  "forgotten" when hitting the map edge.
- Fixed a bug where moving the cursor outside the game window may cause the map
  to scroll.
- Fixed the speed and direction of scrolling with the scroll wheel in help
  pages.
- Changed the panning (i.e. scrolling by dragging) button from the right mouse
  button to the middle mouse button.
- Changed the panning (i.e. scrolling by dragging) direction, so the map moves
  in the expected direction.
- Added map scrolling with WASD.
- Changed the zoom anchor to be relative to the cursor position instead of the
  center of the screen. This makes map navigation much more natural. And it
  plays nice with hitting the map edge (which is more complex then you may first
  expect).
- Normalized scrolling speed for direction and zoom level. (So scrolling
  diagonally while zoomed in no longer feels like mach three.)
- Changed right-click action to show information about construction or tile.
- Added G-key action to toggles the right-click function between construction
  info or tile info.
- Decoupled the speeds of simulation, animation, screen redrawing, and GUI so
  animation and frame rate is no longer dependent on simulation speed. This
  makes the UI much smoother at slow simulation speed.
- Added a page to the MPS display for most constructions that shows monthly
  production/consumption of commodities (both as absolute and percentage).
- Tweaked the total inventory MPS page so that the red/green bars are faster to
  reflect changes in production.
- Constrained he minimap position to avoid showing space outside the map.
- Changed the cursor appearance for panning (i.e. scrolling by dragging).
- Created a (much prettier IMO) black background for the map.
- Fixed icon and desktop file install location for Linux systems.
- Added gd translation for desktop file.

###### Internal
- Fixed a buffer overflow when the home directory path name is very long.
- Fixed a bug in load/save where parks could erroneously get very high
  inventory.
- Fixed a bug where building the project could overwrite changes to GUI dialogs.
- Improved simulation performance. (Fast speed is now blazing fast.)
- Changed the location of save games from ~/.lincity-ng to
  ~/.local/share/lincity-ng. For now, existing save games from the old location
  are still loaded, but subsequent saves go to the new location.
- Replaced the outdated autoconf and Jam build tools with CMake. (Be sure to
  follow the updated instructions for building the project.)
- Changed install directory structure to match GNU style.
- Added binary generation to CPack.
- Added Dockerfile to help create compatible binaries for Ubuntu. (Now we can
  release binary packages.)
- Added a hook in the build system to append the current git hash to the version
  number when not on a release version. This should help reduce ambiguity in bug
  reports.
- Upgraded the MPS display API so constructions can have any number of pages.
- Removed uses of deprecated PhysFS features.
- Cleaned up the logic for binary relocation (and probably fixed a few things).
- Fixed errors and warnings when compiling with C++20.
- Fixed warnings when compiling with -Wall option.
- Added a construction initialization stage to loading and building
  constructions.
- Tidied up the source tree and deleted dead code.
- Added translation file generation build step.

###### Documentation
- Converted the readme to GitHub Markdown.
- Expanded the dependency list in the readme to include build dependencies.
- Included commands for installing dependencies on Ubuntu in the readme.
- Removed dead links in the readme.
- Updated the list of editors in translation instructions.
- Updated formatting in COPYING file.

###### Known Issues
- Untested on Windows and Mac.
- Infrastructure for building for Mac may be missing since updating the build
  tool.
- Ports are OP.
- Does not autodetect screen size on startup in fullscreen.


## LinCity NG 2.9.0

date: 2023-12-18 <br/>
tag: lincity-ng-2.9.0 <br/>
git: ff3e337b

- New sprites
- Overlay sprites
- Roads spawn cars that drive around if there is jobs traffic.
- Right-click switches to query tool.
- Number keys + '`' switches overlay modes.
- Distinction between river, lake, and pond
- Lots of fixes
- Translation updates
- OSX support
- Migraded to SDL2 as backend for interaction with user.


## LinCity NG 2.9.0-beta

date: 2013-12-22 <br/>
tag: lincity-ng-2.9.0-beta <br/>
git: 803a97df <br/>
svn: r1797

- custom map size, see README-Unlimited
- new water management, see README-WaterWell
- more supported languages
- less bugs


## LinCity NG 2.0.0

date: 2009-01-25 <br/>
tag: lincity-ng-2.0.0 <br/>
git: 52160033 <br/>
svn: r1518

- Updated translations (cs, de, nl, pt_BR, ru, sv)
- Use language specific font if `fonts/<style>-<Language>.ttf` exists.
  Note: To use the Japanese translation you have to copy or symlink
  a font with Japanese characters to fonts/sans-ja_JP.ttf.
- improved images
- less bugs


## LinCity NG 1.97.0-beta

date: 2008-12-24 <br/>
tag: lincity-ng-1.97.0-beta <br/>
git: 0e21f221 <br/>
svn: r1474

- less bugs
- up to date English documentation


## LinCity NG 1.92.0-beta

date: 2008-09-13 <br/>
tag: lincity-ng-1.92.0-beta <br/>
git: 66f7f4b1 <br/>
svn: r1456

- water management
- Bridges
- improved images
- changes in savegame format, saves to ~/.lincity-ng/
- documentation is NOT up to date


## LinCity NG 1.1.2

date: 2007-11-04 <br/>
tag: lincity-ng-1.1.2 <br/>
git: 9cf5a31c <br/>
svn: r1270

- Show coal below buildings on mini map.
- Bugfix for solar power plant.
- Updated translations (ca, nl, ru)
- Show range for windmill and coal mine while building.


## LinCity NG 1.1.1

date: 2007-08-19 <br/>
tag: lincity-ng-1.1.1 <br/>
git: 886ebe78 <br/>
svn: r1263

- History in online help
- Heavy industry no longer storing too much coal.
- Sustainability progress is reloaded from saved games.
- Draw range for selected building around cursor
- Online help includes a tutorial
- Russian online help
- Brazilian Portuguese online help
- Change colour of economy tab when people are unemployed or starving
- Fixed problem with multi byte characters in WinXP
- Reuse open statistics dialog


## LinCity NG 1.1.0

date: 2007-02-19 <br/>
tag: lincity-ng-1.1.0 <br/>
git: 43342ee0 <br/>
svn: r1139

- Display correct values for unemployment rate.
- Port connects on all land parts.
- Change background music in menu.
- Show range of markets in traffic view
- French online help
- German online help


## LinCity NG 1.0.3

date: 2006-04-14 <br/>
tag: lincity-ng-1.0.3 <br/>
git: 5b50f632 <br/>
svn: r1089

- Show correct demolition costs for powerlines, substations and farms.
- Quantizing tile-images saves about 12MB.
- Fixed Mills. Now they work.
- Tool-Menu now opens on left mousebutton.
- Separate menus for loading and saving games.


## LinCity NG 1.0.2

date: 2005-11-09 <br/>
tag: lincity-ng-1.0.2 <br/>
git: 035ca774 <br/>
svn: r1063

- Catalan translation
- Spanish translation
- French translation
- Swedish translation
- Fixed: unwanted double-clicks in file menu


## LinCity NG 1.0.1

date: 2005-07-13 <br/>
tag: lincity-ng-1.0.1 <br/>
git: 9ce566c5 <br/>
svn: r1038

- Adjust volume in options
- Load game on doubleclick
- Fixed: Endgame evacuation causes termination of game.
- Fixed: Hightech houses require tech 30, but the tooltip says 20.
- Fixed: Suppressed duplicated tech-messages.
- Fixed: Duplicated command line arguments.
- Fixed: Crash when empty scenario is selected.


## LinCity NG 1.0.0

date: 2005-06-20 <br/>
tag: lincity-ng-1.0.0 <br/>
git: f12f7943 <br/>
svn: r1026

- The first release of LincityNG features everything from classic lincity
  but with brand new graphics and modern user interface.
