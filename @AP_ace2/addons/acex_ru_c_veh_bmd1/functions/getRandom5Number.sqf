/*******************************************************************************
* This function generate random number (from 100 to 999)                       *
*                                                                              *
* @return integer - Generated random nuber                                     *
*                                                                              *
********************************************************************************
*                                                                              *
* $Id:: getRandomNumber.sqf 2 2009-01-17 06:00:33Z ist                      $: *
* author: ist <ist@g76.org> http://g76.org                                     *
*                                                                              *
* LICENSE:  This  program  is  free  software:  you can redistribute it and/or *
* modify it under the terms of the  GNU General Public License as published by *
* the Free Software Foundation, either version 3 of the License,  or  (at your *
* option) any later version.                                                   *
* This program is  distributed in the hope that it will be useful, but WITHOUT *
* ANY  WARRANTY;   without  even  the  implied  warranty of MERCHANTABILITY or *
* FITNESS FOR A PARTICULAR PURPOSE.   See  the  GNU General Public License for *
* more details.                                                                *
* You should have received a copy of the GNU General Public License along with *
* this program. If not, see <http://www.gnu.org/licenses/gpl.txt>.             *
*                                                                              *
*******************************************************************************/
private ["_rand"];

_rand = ceil(random 99998);

if (_rand < 10000) then {
    _rand = _rand + 10000;
};

_rand