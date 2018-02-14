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
#include "../Engine/GameEvent.h"
#include <string>
#include <sstream>

namespace OpenXcom
{

class TextButton;
class Window;
class Text;

/**
 * Notifies the player when a targeted UFO
 * goes outside radar range.
 */
class GeoscapeNewAlienMissionEvent : public GameEvent
{
private:
	AlienMission *_alienmission;
public:
	/// Creates the Ufo Lost state.
	GeoscapeNewAlienMissionEvent(AlienMission *alienmission) : GameEvent(ST_GEOSCAPE_NEWALIENMISSION), _alienmission(alienmission) {}

	AlienMission *getAlienMission() const { return _alienmission; }

	/// Gets the event description
	std::string description() const 
	{ 
		std::stringstream d;
		d << "{GEOSCAPE} New alien mission";
		d << " ID=" << _alienmission->getId();
		d << " REGION=" << _alienmission->getRegion();
		d << " RACE=" << _alienmission->getRace();
		d << " RULE_TYPE=" << _alienmission->getRules().getType();
		return d.str();
	}
};

}
