#ifdef TASKC

#include "Library.h"

void task()
{
	ULL r,g,b;
	read(r,g,b);

	// Make that: r >= g >= b
	if (r < g) swap(r, g);
	if (r < b) swap(r, b);
	if (g < b) swap(g, b);
	/*
	b ************<--d2-->
	g ********************<-------- d1 --------->
	r *******************************************
	*/
	   
	int trash = (r + g + b) % 3;
	int ans = (r + g + b) / 3;
	while (trash > 0 && r > g) { r--; trash--; }
	if (trash > 0) g--;
	if (trash == 2) r--;

	// sort again
	if (r < g) swap(r, g);
	if (r < b) swap(r, b);
	if (g < b) swap(g, b);

	int use = min(r-g, g-b);
	r -= 2*use;
	g -= use;

	if (r == g) {
		write(ans);
		return;
	}

	/*
	b **********
	g **********<------ extra -------->
	r *********************************
	*/


	int extra = r - g;
	if (extra <= b * 3) {
		write(ans);
		return;
	}

	extra -= b * 3;
	write(use + b*2);
}

#endif