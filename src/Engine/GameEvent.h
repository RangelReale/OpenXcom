#pragma once
/*
 * Copyright 2010-2016 OpenXcom Developers.
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <vector>
#include <string>
#include <SDL.h>

namespace OpenXcom
{

enum GameEventType
{
	ST_GEOSCAPE_NEWALIENMISSION = 0,
	ST_GEOSCAPE_UFOSTATECHANGED,
};

/**
 * Game event
 */
class GameEvent
{

protected:
	GameEventType _type;
public:
	/// Creates a new game event
	GameEvent(GameEventType type) : _type(type) {}
	/// Cleans up the game event.
	virtual ~GameEvent() {}
	/// Gets the game event type
	GameEventType type() const { return _type; }
	/// Gets the event description
	virtual std::string description() const { return ""; }
};

}
