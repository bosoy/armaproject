mando_hud_colors_idx = mando_hud_colors_idx + 1;
if (mando_hud_colors_idx == count mando_hud_colors_sets) then
{
   mando_hud_colors_idx = 0;
};
mando_hud_colors = +(mando_hud_colors_sets select mando_hud_colors_idx);
mando_hud_colors_toggled = true; 