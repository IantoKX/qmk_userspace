/* Copyright 2024 IantoKX (@IantoKX)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX, UNICODE_MODE_WINCOMPOSE
#ifndef CONFIG_USER_H
#define CONFIG_USER_H
#define LAYER_STATE_8BIT

// #include QMK_KEYBOARD_CONFIG_H

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE
#define UNICODE_KEY_LNX LCTL(LSFT(KC_U))
#define UNICODE_TYPE_DELAY 25

#define TAPPING_TERM 175
#define TAPPING_TOGGLE 2

#endif
