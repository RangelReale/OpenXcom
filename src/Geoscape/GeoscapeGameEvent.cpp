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
#include "GeoscapeGameEvent.h"
#include "../Savegame/AlienMission.h"
#include "../Mod/RuleAlienMission.h"
#include "../Savegame/Ufo.h"
#include <sstream>

namespace OpenXcom
{

namespace GeoscapeGameEvent
{

/// Gets the event description
std::string NewAlienMission::description() const
{
	std::stringstream d;
	d << "{GEOSCAPE} New alien mission";
	d << " ID=" << _alienmission->getId();
	d << " REGION=" << _alienmission->getRegion();
	d << " RACE=" << _alienmission->getRace();
	d << " RULE_TYPE=" << _alienmission->getRules().getType();
	return d.str();
}

std::string ufoStatusDesc(Ufo::UfoStatus status)
{
	switch (status)
	{
	case Ufo::FLYING:
		return "FLYING";
	case Ufo::LANDED:
		return "LANDED";
	case Ufo::CRASHED:
		return "CRASHED";
	case Ufo::DESTROYED:
		return "DESTROYED";
	}
	return "UNKNOWN";
}

std::string UfoStatusChanged::description() const
{
	std::stringstream d;
	d << "{GEOSCAPE} UFO state changed";
	d << " ID=" << _ufo->getId();
	d << " STATUS=" << ufoStatusDesc(_ufo->getStatus());
	d << " DETECTED=" << _ufo->getDetected() ? "YES" : "NO";
	d << " DIRECTION=" << _ufo->getDirection();
	d << " ALTITUDE=" << _ufo->getAltitude();
	d << " DAMAGE=" << _ufo->getDamage();
	d << " RACE=" << _ufo->getAlienRace();
	d << " MISSION TYPE=" << _ufo->getMissionType();
	return d.str();
}


}

}
