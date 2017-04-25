Private ['_easaDefault','_easaLoadout','_easaVehi','_vehicle'];

EASA_Equip = Compile preProcessFile 'Client\Module\EASA\EASA_Equip.sqf';
EASA_RemoveLoadout = Compile preProcessFile 'Client\Module\EASA\EASA_RemoveLoadout.sqf';

_easaDefault = [];
_easaLoadout = [];
_easaVehi = [];

/* [[Price], [Description], [Weapon, Ammos], [Weapon, Ammos]...] */
_easaVehi = 	_easaVehi + ['Su25_TK_EP1'];
_easaDefault = 	_easaDefault + [[['AirBombLauncher','4Rnd_FAB_250'],['R73Launcher_2','2Rnd_R73']]];
_easaLoadout = 	_easaLoadout + [
if (WF_A2_Arrowhead) then {
 [
  [[1200],['R-73 (6)'],['R73Launcher_2','2Rnd_R73','2Rnd_R73','2Rnd_R73']],
  [[1400],['R-73 (4) | FAB-250 (2)'],['R73Launcher_2','2Rnd_R73','2Rnd_R73'],['AirBombLauncher','2Rnd_FAB_250']],
  [[1600],['R-73 (2) | FAB-250 (4)'],['R73Launcher_2','2Rnd_R73'],['AirBombLauncher','4Rnd_FAB_250']],
  [[1900],['FAB-250 (6)'],['AirBombLauncher','4Rnd_FAB_250','2Rnd_FAB_250']]
 ]
} else {
 [
  [[0],['KAB-500 KR (6)'],['ACE_KAB500KRLauncher','ACE_6Rnd_KAB500KR']],
  [[0],['Kh-29 (6)'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29']],
  [[0],['Kh-29 (4) | KAB-500 L (2)'],['Ch29Launcher_Su34','4Rnd_Ch29'],['ACE_KAB500LLauncher','ACE_6Rnd_KAB500L']],
  [[0],['Kh-29 (4) | R-73 (2)'],['ACE_Kh29Launcher','ACE_4Rnd_Kh29'],['ACE_R73Launcher','ACE_2Rnd_R73']],
  [[0],['R-73 (6)'],['ACE_R73Launcher','ACE_6Rnd_R73']],
  [[0],['R-73 (4) | KAB-500 KR (2)'],['ACE_R73Launcher','ACE_4Rnd_R73'],['ACE_KAB500KRLauncher','ACE_2Rnd_KAB500KR']],
  [[0],['KAB-500 KR (4) | Kh-29 (2)'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR'],['ACE_Kh29Launcher','ACE_2Rnd_Kh29']],
  [[0],['FAB-500  (4) | Kh-29 (2)'],['ACE_FAB500M62Launcher','ACE_4Rnd_FAB500M62'],['ACE_Kh29Launcher','ACE_2Rnd_Kh29']],
  [[0],['FAB-500  (4) | R-73 (2)'],['ACE_FAB500M62Launcher','ACE_4Rnd_FAB500M62'],['ACE_R73Launcher','ACE_2Rnd_R73']],
  [[0],['FAB-500  (6)'],['ACE_FAB500M62Launcher','ACE_6Rnd_FAB500M62']],
  [[0],['R-73 (2) | FAB-250 (4)'],['ACE_R73Launcher','ACE_2Rnd_R73'],['AirBombLauncher','4Rnd_FAB_250']],
  [[0],['R-73 (2) | KAB-500 KR (4)'],['ACE_R73Launcher','ACE_2Rnd_R73'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR']]
 ]
}
];

_easaVehi = 	_easaVehi + ['Su25_Ins'];
_easaDefault = 	_easaDefault + [[['AirBombLauncher','4Rnd_FAB_250'],['R73Launcher_2','2Rnd_R73']]];
_easaLoadout = 	_easaLoadout + [
 [
  [[0],['KAB-500 KR (6)'],['ACE_KAB500KRLauncher','ACE_6Rnd_KAB500KR']],
  [[0],['Kh-29 (6)'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29']],
  [[0],['Kh-29 (4) | KAB-500 L (2)'],['Ch29Launcher_Su34','4Rnd_Ch29'],['ACE_KAB500LLauncher','ACE_6Rnd_KAB500L']],
  [[0],['Kh-29 (4) | R-73 (2)'],['ACE_Kh29Launcher','ACE_4Rnd_Kh29'],['ACE_R73Launcher','ACE_2Rnd_R73']],
  [[0],['R-73 (6)'],['ACE_R73Launcher','ACE_6Rnd_R73']],
  [[0],['R-73 (4) | KAB-500 KR (2)'],['ACE_R73Launcher','ACE_4Rnd_R73'],['ACE_KAB500KRLauncher','ACE_2Rnd_KAB500KR']],
  [[0],['KAB-500 KR (4) | Kh-29 (2)'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR'],['ACE_Kh29Launcher','ACE_2Rnd_Kh29']],
  [[0],['FAB-500  (4) | Kh-29 (2)'],['ACE_FAB500M62Launcher','ACE_4Rnd_FAB500M62'],['ACE_Kh29Launcher','ACE_2Rnd_Kh29']],
  [[0],['FAB-500  (4) | R-73 (2)'],['ACE_FAB500M62Launcher','ACE_4Rnd_FAB500M62'],['ACE_R73Launcher','ACE_2Rnd_R73']],
  [[0],['FAB-500  (6)'],['ACE_FAB500M62Launcher','ACE_6Rnd_FAB500M62']],
  [[0],['R-73 (2) | FAB-250 (4)'],['ACE_R73Launcher','ACE_2Rnd_R73'],['AirBombLauncher','4Rnd_FAB_250']],
  [[0],['R-73 (2) | KAB-500 KR (4)'],['ACE_R73Launcher','ACE_2Rnd_R73'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR']]
 ]
];

_easaVehi = 	_easaVehi + ['Su39'];
_easaDefault = 	_easaDefault + [[['Ch29Launcher','4Rnd_Ch29'],['R73Launcher_2','2Rnd_R73']]];
_easaLoadout = 	_easaLoadout + [
 [
  [[0],['KAB-500 KR (6)'],['ACE_KAB500KRLauncher','ACE_6Rnd_KAB500KR']],
  [[0],['Kh-29 (6)'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29']],
  [[0],['Kh-29 (4) | KAB-500 L (2)'],['Ch29Launcher_Su34','4Rnd_Ch29'],['ACE_KAB500LLauncher','ACE_6Rnd_KAB500L']],
  [[0],['Kh-29 (4) | R-73 (2)'],['ACE_Kh29Launcher','ACE_4Rnd_Kh29'],['ACE_R73Launcher','ACE_2Rnd_R73']],
  [[0],['R-73 (6)'],['ACE_R73Launcher','ACE_6Rnd_R73']],
  [[0],['R-73 (4) | KAB-500 KR (2)'],['ACE_R73Launcher','ACE_4Rnd_R73'],['ACE_KAB500KRLauncher','ACE_2Rnd_KAB500KR']],
  [[0],['KAB-500 KR (4) | Kh-29 (2)'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR'],['ACE_Kh29Launcher','ACE_2Rnd_Kh29']],
  [[0],['FAB-500  (4) | Kh-29 (2)'],['ACE_FAB500M62Launcher','ACE_4Rnd_FAB500M62'],['ACE_Kh29Launcher','ACE_2Rnd_Kh29']],
  [[0],['FAB-500  (4) | R-73 (2)'],['ACE_FAB500M62Launcher','ACE_4Rnd_FAB500M62'],['ACE_R73Launcher','ACE_2Rnd_R73']],
  [[0],['FAB-500  (6)'],['ACE_FAB500M62Launcher','ACE_6Rnd_FAB500M62']],
  [[0],['R-73 (2) | FAB-250 (4)'],['ACE_R73Launcher','ACE_2Rnd_R73'],['AirBombLauncher','4Rnd_FAB_250']],
  [[0],['R-73 (2) | KAB-500 KR (4)'],['ACE_R73Launcher','ACE_2Rnd_R73'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR']]
 ]
];


_easaVehi = 	_easaVehi + ['Su34'];
_easaDefault = 	_easaDefault + [[['ACE_R73Launcher','ACE_4Rnd_R73'],['ACE_R27Launcher','ACE_2Rnd_R27'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29']]];
_easaLoadout = 	_easaLoadout + [
 [
  [[0],['KAB-500 KR (6) | KAB-500 L (6)'],['ACE_KAB500KRLauncher','ACE_6Rnd_KAB500KR'],['ACE_KAB500LLauncher','ACE_6Rnd_KAB500L']],
  [[0],['KAB-500 L (6) | R-73 (4) | R-27 (2)'],['ACE_KAB500LLauncher','ACE_6Rnd_KAB500L'],['ACE_R73Launcher','ACE_2Rnd_R73'],['ACE_R27Launcher','ACE_2Rnd_R27']],
  [[0],['KAB-500 L (6) | KAB-500 KR (4) | R-73 (2)'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR'],['ACE_R73Launcher','ACE_2Rnd_R73'],['ACE_KAB500LLauncher','ACE_6Rnd_KAB500L']],
  [[0],['KAB-500 L (6) | Kh-29 (4) | R-73 (2)'],['ACE_KAB500KRLauncher','ACE_6Rnd_KAB500KR'],['ACE_Kh29Launcher','ACE_4Rnd_Kh29'],['ACE_R73Launcher','ACE_2Rnd_R73']],
  [[0],['KAB-500 KR (4) | Kh-29 (4) | R-73 (4)'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR'],['ACE_Kh29Launcher','ACE_4Rnd_Kh29'],['ACE_R73Launcher','ACE_4Rnd_R73']],
  [[0],['KAB-500 KR (4) | R-73 (6)'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR'],['R73Launcher_2','2Rnd_R73'],['R73Launcher','4Rnd_R73']],
  [[0],['KAB-500 KR (4) | Kh-29 (6)'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29']],
  [[0],['KAB-500 KR (2) | R-73 (8)'],['ACE_KAB500KRLauncher','ACE_2Rnd_KAB500KR'],['R73Launcher','4Rnd_R73','4Rnd_R73']],
  [[0],['KAB-500 KR (2) | R-73 (4) | Ch-29 (6)'],['ACE_KAB500KRLauncher','ACE_2Rnd_KAB500KR'],['ACE_R73Launcher','ACE_4Rnd_R73'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29']],
  [[0],['KAB-500 KR (4) | R-73 (2) | Ch-29 (6)'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR'],['ACE_R73Launcher','ACE_2Rnd_R73'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29']],
  [[0],['R-73 (8) | R-27 (4)'],['ACE_R73Launcher','ACE_6Rnd_R73','ACE_2Rnd_R73'],['ACE_R27Launcher','ACE_4Rnd_R27']],
  [[0],['R-73 (6) | R-27 (6)'],['ACE_R73Launcher','ACE_6Rnd_R73'],['ACE_R27Launcher','ACE_6Rnd_R27']],
  [[0],['Kh-29 (6) | R-73 (4) |KAB-500 KR (2)'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29'],['ACE_R73Launcher','ACE_4Rnd_R73'],['ACE_KAB500KRLauncher','ACE_2Rnd_KAB500KR']],
  [[0],['Kh-29 (6) | R-73 (4) | R-27(2)'],['ACE_R73Launcher','ACE_4Rnd_R73'],['ACE_R27Launcher','ACE_2Rnd_R27'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29']],
  [[0],['Kh-29 (12)'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29','ACE_6Rnd_Kh29']],
  [[0],['R-27 (2) | R-73 (4) | KAB-500 KR (2) | KAB-500 L (2) | FAB-500 (2)'],['ACE_R27Launcher','ACE_2Rnd_R27'],['ACE_R73Launcher','ACE_4Rnd_R73'],['ACE_FAB500M62Launcher','ACE_2Rnd_FAB500M62'],['ACE_KAB500KRLauncher','ACE_2Rnd_KAB500KR'],['ACE_KAB500LLauncher','ACE_2Rnd_KAB500L']],
  [[0],['FAB-500  (6) | KAB-500 L (6)'],['ACE_FAB500M62Launcher','ACE_6Rnd_FAB500M62'],['ACE_KAB500LLauncher','ACE_6Rnd_KAB500L']],
  [[0],['FAB-500  (6) | R-73 (4) | R-27 (2)'],['ACE_FAB500M62Launcher','ACE_6Rnd_FAB500M62'],['ACE_R73Launcher','ACE_2Rnd_R73'],['ACE_R27Launcher','ACE_2Rnd_R27']],
  [[0],['FAB-500  (6) | KAB-500 KR (4) | R-73 (2)'],['ACE_FAB500M62Launcher','ACE_6Rnd_FAB500M62'],['ACE_R73Launcher','ACE_2Rnd_R73'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR']],
  [[0],['FAB-500  (6) | Kh-29 (4) | R-73 (2)'],['ACE_FAB500M62Launcher','ACE_6Rnd_FAB500M62'],['ACE_Kh29Launcher','ACE_4Rnd_Kh29'],['ACE_R73Launcher','ACE_2Rnd_R73']],
  [[0],['FAB-500  (4) | Kh-29 (4) | R-73 (4)'],['ACE_FAB500M62Launcher','ACE_4Rnd_FAB500M62'],['ACE_Kh29Launcher','ACE_4Rnd_Kh29'],['ACE_R73Launcher','ACE_4Rnd_R73']],
  [[0],['FAB-500  (4) | R-73 (6)'],['ACE_FAB500M62Launcher','ACE_4Rnd_FAB500M62'],['R73Launcher_2','2Rnd_R73'],['R73Launcher','4Rnd_R73']],
  [[0],['FAB-500  (4) | Kh-29 (6)'],['ACE_FAB500M62Launcher','ACE_4Rnd_FAB500M62'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29']]
 ]
];

_easaVehi = 	_easaVehi + ['ACE_Su30'];
_easaDefault = 	_easaDefault + [[['ACE_R73Launcher','ACE_4Rnd_R73'],['ACE_R27Launcher','ACE_2Rnd_R27'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29']]];
_easaLoadout = 	_easaLoadout + [
 [
  [[0],['KAB-500 KR (6) | KAB-500 L (6)'],['ACE_KAB500KRLauncher','ACE_6Rnd_KAB500KR'],['ACE_KAB500LLauncher','ACE_6Rnd_KAB500L']],
  [[0],['KAB-500 L (6) | R-73 (4) | R-27 (2)'],['ACE_KAB500LLauncher','ACE_6Rnd_KAB500L'],['ACE_R73Launcher','ACE_2Rnd_R73'],['ACE_R27Launcher','ACE_2Rnd_R27']],
  [[0],['KAB-500 L (6) | KAB-500 KR (4) | R-73 (2)'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR'],['ACE_R73Launcher','ACE_2Rnd_R73'],['ACE_KAB500LLauncher','ACE_6Rnd_KAB500L']],
  [[0],['KAB-500 L (6) | Kh-29 (4) | R-73 (2)'],['ACE_KAB500KRLauncher','ACE_6Rnd_KAB500KR'],['ACE_Kh29Launcher','ACE_4Rnd_Kh29'],['ACE_R73Launcher','ACE_2Rnd_R73']],
  [[0],['KAB-500 KR (4) | Kh-29 (4) | R-73 (4)'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR'],['ACE_Kh29Launcher','ACE_4Rnd_Kh29'],['ACE_R73Launcher','ACE_4Rnd_R73']],
  [[0],['KAB-500 KR (4) | R-73 (6)'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR'],['R73Launcher_2','2Rnd_R73'],['R73Launcher','4Rnd_R73']],
  [[0],['KAB-500 KR (4) | Kh-29 (6)'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29']],
  [[0],['KAB-500 KR (2) | R-73 (8)'],['ACE_KAB500KRLauncher','ACE_2Rnd_KAB500KR'],['R73Launcher','4Rnd_R73','4Rnd_R73']],
  [[0],['KAB-500 KR (2) | R-73 (4) | Ch-29 (6)'],['ACE_KAB500KRLauncher','ACE_2Rnd_KAB500KR'],['ACE_R73Launcher','ACE_4Rnd_R73'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29']],
  [[0],['KAB-500 KR (4) | R-73 (2) | Ch-29 (6)'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR'],['ACE_R73Launcher','ACE_2Rnd_R73'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29']],
  [[0],['R-73 (8) | R-27 (4)'],['ACE_R73Launcher','ACE_6Rnd_R73','ACE_2Rnd_R73'],['ACE_R27Launcher','ACE_4Rnd_R27']],
  [[0],['R-73 (6) | R-27 (6)'],['ACE_R73Launcher','ACE_6Rnd_R73'],['ACE_R27Launcher','ACE_6Rnd_R27']],
  [[0],['Kh-29 (6) | R-73 (4) |KAB-500 KR (2)'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29'],['ACE_R73Launcher','ACE_4Rnd_R73'],['ACE_KAB500KRLauncher','ACE_2Rnd_KAB500KR']],
  [[0],['Kh-29 (6) | R-73 (4) | R-27(2)'],['ACE_R73Launcher','ACE_4Rnd_R73'],['ACE_R27Launcher','ACE_2Rnd_R27'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29']],
  [[0],['Kh-29 (12)'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29','ACE_6Rnd_Kh29']],
  [[0],['R-27 (2) | R-73 (4) | KAB-500 KR (2) | KAB-500 L (2) | FAB-500 (2)'],['ACE_R27Launcher','ACE_2Rnd_R27'],['ACE_R73Launcher','ACE_4Rnd_R73'],['ACE_FAB500M62Launcher','ACE_2Rnd_FAB500M62'],['ACE_KAB500KRLauncher','ACE_2Rnd_KAB500KR'],['ACE_KAB500LLauncher','ACE_2Rnd_KAB500L']],
  [[0],['FAB-500  (6) | KAB-500 L (6)'],['ACE_FAB500M62Launcher','ACE_6Rnd_FAB500M62'],['ACE_KAB500LLauncher','ACE_6Rnd_KAB500L']],
  [[0],['FAB-500  (6) | R-73 (4) | R-27 (2)'],['ACE_FAB500M62Launcher','ACE_6Rnd_FAB500M62'],['ACE_R73Launcher','ACE_2Rnd_R73'],['ACE_R27Launcher','ACE_2Rnd_R27']],
  [[0],['FAB-500  (6) | KAB-500 KR (4) | R-73 (2)'],['ACE_FAB500M62Launcher','ACE_6Rnd_FAB500M62'],['ACE_R73Launcher','ACE_2Rnd_R73'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR']],
  [[0],['FAB-500  (6) | Kh-29 (4) | R-73 (2)'],['ACE_FAB500M62Launcher','ACE_6Rnd_FAB500M62'],['ACE_Kh29Launcher','ACE_4Rnd_Kh29'],['ACE_R73Launcher','ACE_2Rnd_R73']],
  [[0],['FAB-500  (4) | Kh-29 (4) | R-73 (4)'],['ACE_FAB500M62Launcher','ACE_4Rnd_FAB500M62'],['ACE_Kh29Launcher','ACE_4Rnd_Kh29'],['ACE_R73Launcher','ACE_4Rnd_R73']],
  [[0],['FAB-500  (4) | R-73 (6)'],['ACE_FAB500M62Launcher','ACE_4Rnd_FAB500M62'],['R73Launcher_2','2Rnd_R73'],['R73Launcher','4Rnd_R73']],
  [[0],['FAB-500  (4) | Kh-29 (6)'],['ACE_FAB500M62Launcher','ACE_4Rnd_FAB500M62'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29']]
 ]
];

_easaVehi = 	_easaVehi + ['ACE_Su30_des'];
_easaDefault = 	_easaDefault + [[['ACE_R27Launcher','ACE_2Rnd_R27'],['ACE_R73Launcher','ACE_4Rnd_R73'],['ACE_FAB500M62Launcher','ACE_2Rnd_FAB500M62'],['ACE_KAB500KRLauncher','ACE_2Rnd_KAB500KR'],['ACE_KAB500LLauncher','ACE_2Rnd_KAB500L']]];
_easaLoadout = 	_easaLoadout + [
 [
  [[0],['KAB-500 KR (6) | KAB-500 L (6)'],['ACE_KAB500KRLauncher','ACE_6Rnd_KAB500KR'],['ACE_KAB500LLauncher','ACE_6Rnd_KAB500L']],
  [[0],['KAB-500 L (6) | R-73 (4) | R-27 (2)'],['ACE_KAB500LLauncher','ACE_6Rnd_KAB500L'],['ACE_R73Launcher','ACE_2Rnd_R73'],['ACE_R27Launcher','ACE_2Rnd_R27']],
  [[0],['KAB-500 L (6) | KAB-500 KR (4) | R-73 (2)'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR'],['ACE_R73Launcher','ACE_2Rnd_R73'],['ACE_KAB500LLauncher','ACE_6Rnd_KAB500L']],
  [[0],['KAB-500 L (6) | Kh-29 (4) | R-73 (2)'],['ACE_KAB500KRLauncher','ACE_6Rnd_KAB500KR'],['ACE_Kh29Launcher','ACE_4Rnd_Kh29'],['ACE_R73Launcher','ACE_2Rnd_R73']],
  [[0],['KAB-500 KR (4) | Kh-29 (4) | R-73 (4)'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR'],['ACE_Kh29Launcher','ACE_4Rnd_Kh29'],['ACE_R73Launcher','ACE_4Rnd_R73']],
  [[0],['KAB-500 KR (4) | R-73 (6)'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR'],['R73Launcher_2','2Rnd_R73'],['R73Launcher','4Rnd_R73']],
  [[0],['KAB-500 KR (4) | Kh-29 (6)'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29']],
  [[0],['KAB-500 KR (2) | R-73 (8)'],['ACE_KAB500KRLauncher','ACE_2Rnd_KAB500KR'],['R73Launcher','4Rnd_R73','4Rnd_R73']],
  [[0],['KAB-500 KR (2) | R-73 (4) | Ch-29 (6)'],['ACE_KAB500KRLauncher','ACE_2Rnd_KAB500KR'],['ACE_R73Launcher','ACE_4Rnd_R73'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29']],
  [[0],['KAB-500 KR (4) | R-73 (2) | Ch-29 (6)'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR'],['ACE_R73Launcher','ACE_2Rnd_R73'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29']],
  [[0],['R-73 (8) | R-27 (4)'],['ACE_R73Launcher','ACE_6Rnd_R73','ACE_2Rnd_R73'],['ACE_R27Launcher','ACE_4Rnd_R27']],
  [[0],['R-73 (6) | R-27 (6)'],['ACE_R73Launcher','ACE_6Rnd_R73'],['ACE_R27Launcher','ACE_6Rnd_R27']],
  [[0],['Kh-29 (6) | R-73 (4) |KAB-500 KR (2)'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29'],['ACE_R73Launcher','ACE_4Rnd_R73'],['ACE_KAB500KRLauncher','ACE_2Rnd_KAB500KR']],
  [[0],['Kh-29 (6) | R-73 (4) | R-27(2)'],['ACE_R73Launcher','ACE_4Rnd_R73'],['ACE_R27Launcher','ACE_2Rnd_R27'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29']],
  [[0],['Kh-29 (12)'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29','ACE_6Rnd_Kh29']],
  [[0],['R-27 (2) | R-73 (4) | KAB-500 KR (2) | KAB-500 L (2) | FAB-500 (2)'],['ACE_R27Launcher','ACE_2Rnd_R27'],['ACE_R73Launcher','ACE_4Rnd_R73'],['ACE_FAB500M62Launcher','ACE_2Rnd_FAB500M62'],['ACE_KAB500KRLauncher','ACE_2Rnd_KAB500KR'],['ACE_KAB500LLauncher','ACE_2Rnd_KAB500L']],
  [[0],['FAB-500  (6) | KAB-500 L (6)'],['ACE_FAB500M62Launcher','ACE_6Rnd_FAB500M62'],['ACE_KAB500LLauncher','ACE_6Rnd_KAB500L']],
  [[0],['FAB-500  (6) | R-73 (4) | R-27 (2)'],['ACE_FAB500M62Launcher','ACE_6Rnd_FAB500M62'],['ACE_R73Launcher','ACE_2Rnd_R73'],['ACE_R27Launcher','ACE_2Rnd_R27']],
  [[0],['FAB-500  (6) | KAB-500 KR (4) | R-73 (2)'],['ACE_FAB500M62Launcher','ACE_6Rnd_FAB500M62'],['ACE_R73Launcher','ACE_2Rnd_R73'],['ACE_KAB500KRLauncher','ACE_4Rnd_KAB500KR']],
  [[0],['FAB-500  (6) | Kh-29 (4) | R-73 (2)'],['ACE_FAB500M62Launcher','ACE_6Rnd_FAB500M62'],['ACE_Kh29Launcher','ACE_4Rnd_Kh29'],['ACE_R73Launcher','ACE_2Rnd_R73']],
  [[0],['FAB-500  (4) | Kh-29 (4) | R-73 (4)'],['ACE_FAB500M62Launcher','ACE_4Rnd_FAB500M62'],['ACE_Kh29Launcher','ACE_4Rnd_Kh29'],['ACE_R73Launcher','ACE_4Rnd_R73']],
  [[0],['FAB-500  (4) | R-73 (6)'],['ACE_FAB500M62Launcher','ACE_4Rnd_FAB500M62'],['R73Launcher_2','2Rnd_R73'],['R73Launcher','4Rnd_R73']],
  [[0],['FAB-500  (4) | Kh-29 (6)'],['ACE_FAB500M62Launcher','ACE_4Rnd_FAB500M62'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29']]
 ]
];



_easaVehi = 	_easaVehi + ['ACE_Su27_CAS'];
_easaDefault = 	_easaDefault + [[['ACE_R73Launcher','ACE_4Rnd_R73'],['ACE_R27Launcher','ACE_2Rnd_R27']]];
_easaLoadout = 	_easaLoadout + [
 [
  [[0],['KAB-500 L (6)'],['ACE_KAB500LLauncher','ACE_6Rnd_KAB500L']],
  [[0],['KAB-500 L (2) | R-73 (4)'],['ACE_KAB500LLauncher','ACE_2Rnd_KAB500L'],['ACE_R73Launcher','ACE_4Rnd_R73']],
  [[0],['KAB-500 L (4) | Kh-29 (2)'],['ACE_KAB500LLauncher','ACE_4Rnd_KAB500L'],['ACE_Kh29Launcher','ACE_2Rnd_Kh29']],
  [[0],['R-73 (6)'],['ACE_R73Launcher','ACE_6Rnd_R73']],
  [[0],['R-73 (4) | R-27 (2)'],['ACE_R73Launcher','ACE_4Rnd_R73'],['ACE_R27Launcher','ACE_2Rnd_R27']],
  [[0],['Kh-29 (6)'],['ACE_Kh29Launcher','ACE_6Rnd_Kh29']],
  [[0],['Kh-29 (4) | R-27(2)'],['ACE_R27Launcher','ACE_2Rnd_R27'],['ACE_Kh29Launcher','ACE_4Rnd_Kh29']],
  [[0],['Kh-29 (2)| R-73 (4)'],['ACE_Kh29Launcher','ACE_2Rnd_Kh29'],['ACE_R73Launcher','ACE_4Rnd_R73']],
  [[0],['FAB-500  (6)'],['ACE_FAB500M62Launcher','ACE_6Rnd_FAB500M62']],
  [[0],['FAB-500  (4) | Kh-29 (2)'],['ACE_FAB500M62Launcher','ACE_4Rnd_FAB500M62'],['ACE_Kh29Launcher','ACE_2Rnd_Kh29']],
  [[0],['FAB-500  (4) | R-73 (2)'],['ACE_FAB500M62Launcher','ACE_4Rnd_FAB500M62'],['R73Launcher_2','2Rnd_R73']],
  [[0],['FAB-500  (4) | R-27 (2)'],['ACE_FAB500M62Launcher','ACE_4Rnd_FAB500M62'],['ACE_R27Launcher','ACE_2Rnd_R27']]
 ]
];


_easaVehi = 	_easaVehi + ['Mi24_P'];
_easaDefault = 	_easaDefault + [[['HeliBombLauncher','2Rnd_FAB_250']]];
_easaLoadout = 	_easaLoadout + [
 [
  [[0],['FAB-250 (2)'],['HeliBombLauncher','2Rnd_FAB_250']],
  [[0],['R-73 (2)'],['R73Launcher_2','2Rnd_R73']]
 ]
];

_easaVehi = 	_easaVehi + ['Ka52'];
_easaDefault = 	_easaDefault + [[['VikhrLauncher','12Rnd_Vikhr_KA50']]];
_easaLoadout = 	_easaLoadout + [
 [
  [[0],['Vikhr (12)'],['VikhrLauncher','12Rnd_Vikhr_KA50']],
  [[0],['R-73 (12)'],['ACE_R73Launcher','ACE_6Rnd_R73','ACE_6Rnd_R73']]
 ]
];

_easaVehi = 	_easaVehi + ['Ka52Black'];
_easaDefault = 	_easaDefault + [[['VikhrLauncher','12Rnd_Vikhr_KA50']]];
_easaLoadout = 	_easaLoadout + [
 [
  [[0],['Vikhr (12)'],['VikhrLauncher','12Rnd_Vikhr_KA50']],
  [[0],['R-73 (12)'],['ACE_R73Launcher','ACE_6Rnd_R73','ACE_6Rnd_R73']]
 ]
];

_easaVehi = 	_easaVehi + ['F35B'];
_easaDefault = 	_easaDefault + [[['BombLauncherF35','2Rnd_GBU12'],['SidewinderLaucher_F35','2Rnd_Sidewinder_F35']]];
_easaLoadout = 	_easaLoadout + [
 [
  [[0],['GBU-12 (4)'],['BombLauncherA10','4Rnd_GBU12']],
  [[0],['GBU-12 (2) | AIM-9L (2)'],['BombLauncherF35','2Rnd_GBU12'],['SidewinderLaucher_F35','2Rnd_Sidewinder_F35']],
  [[0],['GBU-12 (2) | AGM-65 (2)'],['BombLauncherF35','2Rnd_GBU12'],['MaverickLauncher','2Rnd_Maverick_A10']],
  [[0],['AGM-65 (4)'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10']],
  [[0],['AIM-9L (4)'],['SidewinderLaucher','4Rnd_Sidewinder_AV8B']]
 ]
];

_easaVehi = 	_easaVehi + ['AV8B'];
_easaDefault = 	_easaDefault + [[['BombLauncher','6Rnd_GBU12_AV8B']]];
_easaLoadout = 	_easaLoadout + [
 [
  [[0],['Mk82 (6)'],['Mk82BombLauncher_6','6Rnd_Mk82']],
  [[0],['GBU-12 (6)'],['BombLauncher','6Rnd_GBU12_AV8B']],
  [[0],['GBU-12 (4) | AIM-9L (2)'],['BombLauncherA10','4Rnd_GBU12'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z']],
  [[0],['GBU-12 (4) | AGM-65 (2)'],['BombLauncherA10','4Rnd_GBU12'],['MaverickLauncher','2Rnd_Maverick_A10']],
  [[0],['GBU-12 (2) | AIM-9L (4)'],['ACE_BombLauncher','ACE_1Rnd_GBU12','ACE_1Rnd_GBU12'],['SidewinderLaucher','4Rnd_Sidewinder_AV8B']],
  [[0],['GBU-12 (2) | AIM-9L (2) | AGM-65 (2)'],['ACE_BombLauncher','ACE_1Rnd_GBU12','ACE_1Rnd_GBU12'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z'],['MaverickLauncher','2Rnd_Maverick_A10']],
  [[0],['CBU-87 (6)'],['ACE_CBU87_Bomblauncher','ACE_6Rnd_CBU87']],
  [[0],['CBU-87 (4) | AIM-9L (2)'],['ACE_CBU87_Bomblauncher','ACE_4Rnd_CBU87'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z']],
  [[0],['CBU-87 (4) | AGM-65 (2)'],['ACE_CBU87_Bomblauncher','ACE_4Rnd_CBU87'],['MaverickLauncher','2Rnd_Maverick_A10']],
  [[0],['CBU-87 (2) | AIM-9L (4)'],['ACE_CBU87_Bomblauncher','ACE_2Rnd_CBU87'],['SidewinderLaucher','4Rnd_Sidewinder_AV8B']],
  [[0],['CBU-87 (2) | AIM-9L (2) | AGM-65 (2)'],['ACE_CBU87_Bomblauncher','ACE_2Rnd_CBU87'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z'],['MaverickLauncher','2Rnd_Maverick_A10']],
  [[0],['AIM-9L (6)'],['SidewinderLaucher','4Rnd_Sidewinder_AV8B'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z']],
  [[0],['AGM-65 (6)'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10','2Rnd_Maverick_A10']]
 ]
];

_easaVehi = 	_easaVehi + ['AV8B2'];
_easaDefault = 	_easaDefault + [[['Mk82BombLauncher_6','6Rnd_Mk82'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z']]];
_easaLoadout = 	_easaLoadout + [
 [
  [[0],['GBU-12 (8)'],['BombLauncherA10','4Rnd_GBU12','4Rnd_GBU12']],
  [[0],['GBU-12 (6) | AGM-65 (2)'],['BombLauncher','6Rnd_GBU12_AV8B'],['MaverickLauncher','2Rnd_Maverick_A10']],
  [[0],['GBU-12 (6) | AIM-9L (2)'],['BombLauncher','6Rnd_GBU12_AV8B'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z']],
  [[0],['GBU-12 (4) | AGM-65 (4)'],['BombLauncherA10','4Rnd_GBU12'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10']],
  [[0],['GBU-12 (4) | AIM-9L (4)'],['BombLauncherA10','4Rnd_GBU12'],['SidewinderLaucher','4Rnd_Sidewinder_AV8B']],
  [[0],['GBU-12 (4) | AIM-9L (2) | AGM-65 (2)'],['BombLauncherA10','4Rnd_GBU12'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z'],['MaverickLauncher','2Rnd_Maverick_A10']],
  [[0],['GBU-12 (2) | AIM-9L (4) | AGM-65 (2)'],['ACE_BombLauncher','ACE_1Rnd_GBU12','ACE_1Rnd_GBU12'],['SidewinderLaucher','4Rnd_Sidewinder_AV8B'],['MaverickLauncher','2Rnd_Maverick_A10']],
  [[0],['GBU-12 (2) | AIM-9L (2) | AGM-65 (4)'],['ACE_BombLauncher','ACE_1Rnd_GBU12','ACE_1Rnd_GBU12'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10']],
  [[0],['GBU-12 (2) | AIM-9L (6)'],['ACE_BombLauncher','ACE_1Rnd_GBU12','ACE_1Rnd_GBU12'],['SidewinderLaucher','4Rnd_Sidewinder_AV8B'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z']],
  [[0],['GBU-12 (2) | AGM-65 (6)'],['ACE_BombLauncher','ACE_1Rnd_GBU12','ACE_1Rnd_GBU12'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10','2Rnd_Maverick_A10']],
  [[0],['Mk82 (6) | AIM-9L (2)'],['Mk82BombLauncher_6','6Rnd_Mk82'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z']],
  [[0],['Mk82 (6) | AGM-65 (2)'],['Mk82BombLauncher_6','6Rnd_Mk82'],['MaverickLauncher','2Rnd_Maverick_A10']],
  [[0],['Mk82 (6) | GBU-12 (2)'],['Mk82BombLauncher_6','6Rnd_Mk82'],['ACE_BombLauncher','ACE_1Rnd_GBU12','ACE_1Rnd_GBU12']],
  [[0],['AGM-65 (8)'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10','2Rnd_Maverick_A10','2Rnd_Maverick_A10']],
  [[0],['AGM-65 (4) | AIM-9L (4)'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10'],['SidewinderLaucher','4Rnd_Sidewinder_AV8B']],
  [[0],['AGM-65 (6) | AIM-9L (2)'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10','2Rnd_Maverick_A10'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z']],
  [[0],['CBU-87 (8)'],['ACE_CBU87_Bomblauncher','ACE_8Rnd_CBU87']],
  [[0],['CBU-87 (6) | AGM-65 (2)'],['ACE_CBU87_Bomblauncher','ACE_6Rnd_CBU87'],['MaverickLauncher','2Rnd_Maverick_A10']],
  [[0],['CBU-87 (6) | AIM-9L (2)'],['ACE_CBU87_Bomblauncher','ACE_6Rnd_CBU87'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z']],
  [[0],['CBU-87 (4) | AGM-65 (4)'],['ACE_CBU87_Bomblauncher','ACE_4Rnd_CBU87'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10']],
  [[0],['CBU-87 (4) | AIM-9L (4)'],['ACE_CBU87_Bomblauncher','ACE_4Rnd_CBU87'],['SidewinderLaucher','4Rnd_Sidewinder_AV8B']],
  [[0],['CBU-87 (4) | AIM-9L (2) | AGM-65 (2)'],['ACE_CBU87_Bomblauncher','ACE_4Rnd_CBU87'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z'],['MaverickLauncher','2Rnd_Maverick_A10']],
  [[0],['CBU-87 (2) | AIM-9L (4) | AGM-65 (2)'],['ACE_CBU87_Bomblauncher','ACE_2Rnd_CBU87'],['SidewinderLaucher','4Rnd_Sidewinder_AV8B'],['MaverickLauncher','2Rnd_Maverick_A10']],
  [[0],['CBU-87 (2) | AIM-9L (2) | AGM-65 (4)'],['ACE_CBU87_Bomblauncher','ACE_2Rnd_CBU87'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10']],
  [[0],['CBU-87 (2) | AIM-9L (6)'],['ACE_CBU87_Bomblauncher','ACE_2Rnd_CBU87'],['SidewinderLaucher','4Rnd_Sidewinder_AV8B'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z']],
  [[0],['CBU-87 (2) | AGM-65 (6)'],['ACE_CBU87_Bomblauncher','ACE_2Rnd_CBU87'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10','2Rnd_Maverick_A10']],
  [[0],['AIM-9L (8)'],['SidewinderLaucher_AH64','8Rnd_Sidewinder_AH64']],
  [[0],['AIM-9L (6) | AGM-65 (2)'],['SidewinderLaucher','4Rnd_Sidewinder_AV8B'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z'],['MaverickLauncher','2Rnd_Maverick_A10']]
 ]
];

_easaVehi = 	_easaVehi + ['ACE_A10_CBU87'];
_easaDefault = 	_easaDefault + [[['ACE_CBU87_Bomblauncher','ACE_4Rnd_CBU87'],['MaverickLauncher','2Rnd_Maverick_A10'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z']]];
_easaLoadout = 	_easaLoadout + [
if (WF_A2_Arrowhead) then {
 [
  [[0],['GBU-12 (8)'],['BombLauncherA10','4Rnd_GBU12','4Rnd_GBU12']],
  [[0],['GBU-12 (4) | AGM-65 (4)'],['BombLauncherA10','4Rnd_GBU12'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10']],
  [[0],['GBU-12 (4) | AIM-9L (4)'],['BombLauncherA10','4Rnd_GBU12'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z','2Rnd_Sidewinder_AH1Z']],
  [[0],['GBU-12 (4) | AIM-9L (2) | AGM-65 (2)'],['BombLauncherA10','4Rnd_GBU12'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z'],['MaverickLauncher','2Rnd_Maverick_A10']],
  [[0],['AGM-65 (8)'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10','2Rnd_Maverick_A10','2Rnd_Maverick_A10']],
  [[0],['AGM-65 (4) | AIM-9L (4)'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z','2Rnd_Sidewinder_AH1Z']],
  [[0],['AGM-65 (6) | AIM-9L (2)'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10','2Rnd_Maverick_A10'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z']],
  [[0],['AGM-114 (8)'],['HellfireLauncher','8Rnd_Hellfire']],
  [[0],['AIM-9L (8)'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z','2Rnd_Sidewinder_AH1Z','2Rnd_Sidewinder_AH1Z','2Rnd_Sidewinder_AH1Z']],
  [[0],['AIM-9L (6) | AGM-65 (2)'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z','2Rnd_Sidewinder_AH1Z','2Rnd_Sidewinder_AH1Z'],['MaverickLauncher','2Rnd_Maverick_A10']]
 ]
} else {
 [
  [[0],['GBU-12 (8)'],['BombLauncherA10','4Rnd_GBU12','4Rnd_GBU12']],
  [[0],['GBU-12 (6) | AGM-65 (2)'],['BombLauncher','6Rnd_GBU12_AV8B'],['MaverickLauncher','2Rnd_Maverick_A10']],
  [[0],['GBU-12 (6) | AIM-9L (2)'],['BombLauncher','6Rnd_GBU12_AV8B'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z']],
  [[0],['GBU-12 (4) | AGM-65 (4)'],['BombLauncherA10','4Rnd_GBU12'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10']],
  [[0],['GBU-12 (4) | AIM-9L (4)'],['BombLauncherA10','4Rnd_GBU12'],['SidewinderLaucher','4Rnd_Sidewinder_AV8B']],
  [[0],['GBU-12 (4) | AIM-9L (2) | AGM-65 (2)'],['BombLauncherA10','4Rnd_GBU12'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z'],['MaverickLauncher','2Rnd_Maverick_A10']],
  [[0],['GBU-12 (2) | AIM-9L (4) | AGM-65 (2)'],['ACE_BombLauncher','ACE_1Rnd_GBU12','ACE_1Rnd_GBU12'],['SidewinderLaucher','4Rnd_Sidewinder_AV8B'],['MaverickLauncher','2Rnd_Maverick_A10']],
  [[0],['GBU-12 (2) | AIM-9L (2) | AGM-65 (4)'],['ACE_BombLauncher','ACE_1Rnd_GBU12','ACE_1Rnd_GBU12'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10']],
  [[0],['GBU-12 (2) | AIM-9L (6)'],['ACE_BombLauncher','ACE_1Rnd_GBU12','ACE_1Rnd_GBU12'],['SidewinderLaucher','4Rnd_Sidewinder_AV8B'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z']],
  [[0],['GBU-12 (2) | AGM-65 (6)'],['ACE_BombLauncher','ACE_1Rnd_GBU12','ACE_1Rnd_GBU12'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10','2Rnd_Maverick_A10']],
  [[0],['Mk82 (6) | AIM-9L (2)'],['Mk82BombLauncher_6','6Rnd_Mk82'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z']],
  [[0],['Mk82 (6) | AGM-65 (2)'],['Mk82BombLauncher_6','6Rnd_Mk82'],['MaverickLauncher','2Rnd_Maverick_A10']],
  [[0],['Mk82 (6) | GBU-12 (2)'],['Mk82BombLauncher_6','6Rnd_Mk82'],['ACE_BombLauncher','ACE_1Rnd_GBU12','ACE_1Rnd_GBU12']],
  [[0],['AGM-65 (8)'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10','2Rnd_Maverick_A10','2Rnd_Maverick_A10']],
  [[0],['AGM-65 (4) | AIM-9L (4)'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10'],['SidewinderLaucher','4Rnd_Sidewinder_AV8B']],
  [[0],['AGM-65 (6) | AIM-9L (2)'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10','2Rnd_Maverick_A10'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z']],
  [[0],['CBU-87 (4) | AIM-9L (2) | AGM-65 (2)'],['ACE_CBU87_Bomblauncher','ACE_4Rnd_CBU87'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z'],['MaverickLauncher','2Rnd_Maverick_A10']],
  [[0],['CBU-87 (8)'],['ACE_CBU87_Bomblauncher','ACE_8Rnd_CBU87']],
  [[0],['CBU-87 (6) | AGM-65 (2)'],['ACE_CBU87_Bomblauncher','ACE_6Rnd_CBU87'],['MaverickLauncher','2Rnd_Maverick_A10']],
  [[0],['CBU-87 (6) | AIM-9L (2)'],['ACE_CBU87_Bomblauncher','ACE_6Rnd_CBU87'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z']],
  [[0],['CBU-87 (4) | AGM-65 (4)'],['ACE_CBU87_Bomblauncher','ACE_4Rnd_CBU87'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10']],
  [[0],['CBU-87 (4) | AIM-9L (4)'],['ACE_CBU87_Bomblauncher','ACE_4Rnd_CBU87'],['SidewinderLaucher','4Rnd_Sidewinder_AV8B']],
  [[0],['CBU-87 (2) | AIM-9L (4) | AGM-65 (2)'],['ACE_CBU87_Bomblauncher','ACE_2Rnd_CBU87'],['SidewinderLaucher','4Rnd_Sidewinder_AV8B'],['MaverickLauncher','2Rnd_Maverick_A10']],
  [[0],['CBU-87 (2) | AIM-9L (2) | AGM-65 (4)'],['ACE_CBU87_Bomblauncher','ACE_2Rnd_CBU87'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10']],
  [[0],['CBU-87 (2) | AIM-9L (6)'],['ACE_CBU87_Bomblauncher','ACE_2Rnd_CBU87'],['SidewinderLaucher','4Rnd_Sidewinder_AV8B'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z']],
  [[0],['CBU-87 (2) | AGM-65 (6)'],['ACE_CBU87_Bomblauncher','ACE_2Rnd_CBU87'],['MaverickLauncher','2Rnd_Maverick_A10','2Rnd_Maverick_A10','2Rnd_Maverick_A10']],
  [[0],['AIM-9L (8)'],['SidewinderLaucher_AH64','8Rnd_Sidewinder_AH64']],
  [[0],['AIM-9L (6) | AGM-65 (2)'],['SidewinderLaucher','4Rnd_Sidewinder_AV8B'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z'],['MaverickLauncher','2Rnd_Maverick_A10']]
 ]
}
];

_easaVehi = 	_easaVehi + ['AH64D_EP1'];
_easaDefault = 	_easaDefault + [[['HellfireLauncher','ACE_4Rnd_Hellfire'],['ACE_HellfireLauncher_Apache','ACE_4Rnd_Hellfire_L']]];
_easaLoadout = 	_easaLoadout + [
if (WF_A2_Arrowhead) then {
 [
  [[0],['AGM-114 (8)'],['HellfireLauncher','8Rnd_Hellfire']],
  [[0],['AIM-9L (8)'],['SidewinderLaucher_AH1Z','2Rnd_Sidewinder_AH1Z','2Rnd_Sidewinder_AH1Z','2Rnd_Sidewinder_AH1Z','2Rnd_Sidewinder_AH1Z']]
 ]
} else {
 [
  [[0],['AGM-114K (8)'],['ACE_HellfireLauncher','8Rnd_Hellfire']],
  [[0],['AGM-114L (8)'],['ACE_HellfireLauncher_Apache','ACE_8Rnd_Hellfire_L']],
  [[0],['AGM-114K (4) | AGM-114L (4)'],['HellfireLauncher','ACE_4Rnd_Hellfire'],['ACE_HellfireLauncher_Apache','ACE_4Rnd_Hellfire_L']],
  [[0],['AIM-9L (8)'],['SidewinderLaucher_AH64','8Rnd_Sidewinder_AH64']]
 ]
}
];

_easaVehi = 	_easaVehi + ['AH1Z'];
_easaDefault = 	_easaDefault + [[['ACE_HellfireLauncher','8Rnd_Hellfire']]];
_easaLoadout = 	_easaLoadout + [
 [
  [[0],['AGM-114K (8)'],['ACE_HellfireLauncher','8Rnd_Hellfire']],
  [[0],['AGM-114L (8)'],['ACE_HellfireLauncher_Apache','ACE_8Rnd_Hellfire_L']],
  [[0],['AGM-114K (4) | AGM-114L (4)'],['HellfireLauncher','ACE_4Rnd_Hellfire'],['ACE_HellfireLauncher_Apache','ACE_4Rnd_Hellfire_L']],
  [[0],['AIM-9L (8)'],['SidewinderLaucher_AH64','8Rnd_Sidewinder_AH64']]
 ]
];

_easaVehi = 	_easaVehi + ['ACE_AH1Z_AGM_AGM_W'];
_easaDefault = 	_easaDefault + [[['ACE_HellfireLauncher','ACE_16Rnd_Hellfire']]];
_easaLoadout = 	_easaLoadout + [
 [
  [[0],['AGM-114K (16)'],['ACE_HellfireLauncher','ACE_16Rnd_Hellfire']],
  [[0],['AGM-114L (16)'],['ACE_HellfireLauncher_Apache','ACE_16Rnd_Hellfire_L']],
  [[0],['AGM-114K (8) | AGM-114L (8)'],['HellfireLauncher','ACE_8Rnd_Hellfire'],['ACE_HellfireLauncher_Apache','ACE_8Rnd_Hellfire_L']],
  [[0],['AIM-9L (8) | AGM-114K (8)'],['SidewinderLaucher_AH64','8Rnd_Sidewinder_AH64'],['ACE_HellfireLauncher','ACE_8Rnd_Hellfire']],
  [[0],['AIM-9L (8) | AGM-114L (8)'],['SidewinderLaucher_AH64','8Rnd_Sidewinder_AH64'],['ACE_HellfireLauncher_Apache','ACE_8Rnd_Hellfire_L']],
  [[0],['AIM-9L (16)'],['SidewinderLaucher_AH64','8Rnd_Sidewinder_AH64','8Rnd_Sidewinder_AH64']]
 ]
];

['WFBE_EASA_Vehicles',_easaVehi,true] Call SetNamespace;
['WFBE_EASA_Loadouts',_easaLoadout,true] Call SetNamespace;
['WFBE_EASA_Default',_easaDefault,true] Call SetNamespace;