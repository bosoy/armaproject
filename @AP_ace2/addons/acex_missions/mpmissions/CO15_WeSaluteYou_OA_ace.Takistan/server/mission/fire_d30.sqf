
while {true} do {
	d30_1 doWatch [(getPos d30_1 select 0), (getPos d30_1 select 1), (getPos d30_1 select 2)+( 1.4 +(random 0.3))];
	d30_2 doWatch [(getPos d30_2 select 0), (getPos d30_2 select 1), (getPos d30_2 select 2)+( 1.5 +(random 0.3))];
	d30_3 doWatch [(getPos d30_3 select 0), (getPos d30_3 select 1), (getPos d30_3 select 2)+( 1.6 +(random 0.3))];

	sleep 2;

	d30_1 addMagazine "ARTY_30Rnd_122mmHE_D30";
	d30_2 addMagazine "ARTY_30Rnd_122mmHE_D30";
	d30_3 addMagazine "ARTY_30Rnd_122mmHE_D30";

	reload d30_1;
	reload d30_2;
	reload d30_3;

	sleep 2;

	d30_1 fire "D30";
	sleep (0.2 +(random 0.4));
	d30_2 fire "D30";
	sleep (0.2 +(random 0.4));
	d30_3 fire "D30";

	sleep (12 + random 15);
};

// Somehow the D30 stop firing... maybe the loop has a limit... so test this quickfix... call loop again
while {true} do {
	d30_1 doWatch [(getPos d30_1 select 0), (getPos d30_1 select 1), (getPos d30_1 select 2)+( 1.4 +(random 0.3))];
	d30_2 doWatch [(getPos d30_2 select 0), (getPos d30_2 select 1), (getPos d30_2 select 2)+( 1.5 +(random 0.3))];
	d30_3 doWatch [(getPos d30_3 select 0), (getPos d30_3 select 1), (getPos d30_3 select 2)+( 1.6 +(random 0.3))];

	sleep 2;

	d30_1 addMagazine "ARTY_30Rnd_122mmHE_D30";
	d30_2 addMagazine "ARTY_30Rnd_122mmHE_D30";
	d30_3 addMagazine "ARTY_30Rnd_122mmHE_D30";

	reload d30_1;
	reload d30_2;
	reload d30_3;

	sleep 2;

	d30_1 fire "D30";
	sleep (0.2 +(random 0.4));
	d30_2 fire "D30";
	sleep (0.2 +(random 0.4));
	d30_3 fire "D30";

	sleep (12 + random 15);
};

while {true} do {
	d30_1 doWatch [(getPos d30_1 select 0), (getPos d30_1 select 1), (getPos d30_1 select 2)+( 1.4 +(random 0.3))];
	d30_2 doWatch [(getPos d30_2 select 0), (getPos d30_2 select 1), (getPos d30_2 select 2)+( 1.5 +(random 0.3))];
	d30_3 doWatch [(getPos d30_3 select 0), (getPos d30_3 select 1), (getPos d30_3 select 2)+( 1.6 +(random 0.3))];

	sleep 2;

	d30_1 addMagazine "ARTY_30Rnd_122mmHE_D30";
	d30_2 addMagazine "ARTY_30Rnd_122mmHE_D30";
	d30_3 addMagazine "ARTY_30Rnd_122mmHE_D30";

	reload d30_1;
	reload d30_2;
	reload d30_3;

	sleep 2;

	d30_1 fire "D30";
	sleep (0.2 +(random 0.4));
	d30_2 fire "D30";
	sleep (0.2 +(random 0.4));
	d30_3 fire "D30";

	sleep (12 + random 15);
};

while {true} do {
	d30_1 doWatch [(getPos d30_1 select 0), (getPos d30_1 select 1), (getPos d30_1 select 2)+( 1.4 +(random 0.3))];
	d30_2 doWatch [(getPos d30_2 select 0), (getPos d30_2 select 1), (getPos d30_2 select 2)+( 1.5 +(random 0.3))];
	d30_3 doWatch [(getPos d30_3 select 0), (getPos d30_3 select 1), (getPos d30_3 select 2)+( 1.6 +(random 0.3))];

	sleep 2;

	d30_1 addMagazine "ARTY_30Rnd_122mmHE_D30";
	d30_2 addMagazine "ARTY_30Rnd_122mmHE_D30";
	d30_3 addMagazine "ARTY_30Rnd_122mmHE_D30";

	reload d30_1;
	reload d30_2;
	reload d30_3;

	sleep 2;

	d30_1 fire "D30";
	sleep (0.2 +(random 0.4));
	d30_2 fire "D30";
	sleep (0.2 +(random 0.4));
	d30_3 fire "D30";

	sleep (12 + random 15);
};
