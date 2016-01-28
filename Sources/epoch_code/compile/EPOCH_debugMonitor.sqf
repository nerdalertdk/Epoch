/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch debug monitor

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/EPOCH_debugMonitor.sqf
*/
private["_hours"];
_hours = floor(servertime/60/60);

_customVars = "";
{
	if !(_x in ["AliveTime","SpawnArray","HitPoints"]) then {
		_customVars = _customVars + format["<t size='1.15' font='puristaLight' align='left'>%1: </t><t size='1.15' font='puristaLight' align='right'>%2</t><br/>", _x,missionNamespace getVariable [format ["EPOCH_player%1",_x],EPOCH_defaultVars select _forEachIndex]];
	}
}forEach EPOCH_customVars;

hintSilent parseText format ["
	<t size='1.25' font='puristaLight' align='center'>Welcome to Epoch Alpha</t><br/>
	<t size='1.18' font='puristaLight' align='center'>Current Version: %1</t><br/>

	" + _customVars + "
	<br/>

	<t size='1.15' font='puristaLight' align='left'>Fatigue: </t><t size='1.15' font='puristaLight' align='right'>%2</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Damage: </t><t size='1.15' font='puristaLight' align='right'>%3</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Bleeding: </t><t size='1.15' font='puristaLight' align='right'>%4</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Bleed Time: </t><t size='1.15' font='puristaLight' align='right'>%5</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Oxygen: </t><t size='1.15' font='puristaLight' align='right'>%6</t><br/>
	<br/>
	<t size='1.15' font='puristaLight' align='left'>Air Temp: </t><t size='1.15' font='puristaLight' align='right'>%7</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Water Temp: </t><t size='1.15' font='puristaLight' align='right'>%8</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Rain: </t><t size='1.15' font='puristaLight' align='right'>%9</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Overcast: </t><t size='1.15' font='puristaLight' align='right'>%10</t><br/>
	<br/>
	<t size='1.15' font='puristaLight' align='left'>Hours Alive: </t><t size='1.15' font='puristaLight' align='right'>%11</t><br/>
	<t size='1.15' font='puristaLight' align='left'>FPS: </t><t size='1.15' font='puristaLight' align='right'>%12</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Server uptime: </t><t size='1.15' font='puristaLight' align='right'>%13h %14m</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Server FPS: </t><t size='1.15' font='puristaLight' align='right'>%15</t><br/>",
	getText(configFile >> "CfgMods" >> "Epoch" >> "version"),
	(getFatigue player),
	(damage player),
	(isBleeding player),
	(getBleedingRemaining player),
	(getOxygenRemaining player),

	EPOCH_CURRENT_WEATHER,
	(EPOCH_CURRENT_WEATHER/2),
	rain,
	overcast,

	round(EPOCH_playerAliveTime/360)/10,
	round diag_fps,
	_hours,
	round((serverTime/60)-(_hours*60)),
	if (typeName EPOCH_diag_fps == "SCALAR") then [{EPOCH_diag_fps},{"MANIPULATED"}]
];