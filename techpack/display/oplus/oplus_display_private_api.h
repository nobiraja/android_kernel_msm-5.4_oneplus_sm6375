/***************************************************************
** Copyright (C),  2018,  OPLUS Mobile Comm Corp.,  Ltd
** File : oplus_display_private_api.h
** Description : oplus display private api implement
** Version : 1.0
** Date : 2018/03/20
** Author : Jie.Hu@PSW.MM.Display.Stability
**
** ------------------------------- Revision History: -----------
**  <author>        <data>        <version >        <desc>
**   Hu.Jie          2018/03/20        1.0           Build this moudle
******************************************************************/
#ifndef _OPLUS_DISPLAY_PRIVATE_API_H_
#define _OPLUS_DISPLAY_PRIVATE_API_H_

#include <linux/err.h>
#include <linux/list.h>
#include <linux/of.h>
#include "msm_drv.h"
#include "sde_connector.h"
#include "sde_crtc.h"
#include "sde_hw_dspp.h"
#include "sde_plane.h"
#include "msm_mmu.h"
#include "dsi_display.h"
#include "dsi_panel.h"
#include "dsi_ctrl.h"
#include "dsi_ctrl_hw.h"
#include "dsi_drm.h"
#include "dsi_clk.h"
#include "dsi_pwr.h"
#include "sde_dbg.h"
#include <linux/kobject.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/module.h>
#include <linux/init.h>
#include <drm/drm_mipi_dsi.h>
#include "oplus_dsi_support.h"


#ifdef OPLUS_FEATURE_AOD_RAMLESS
struct aod_area {
	int enable;
	int x;
	int y;
	int w;
	int h;
	int color;
	int bitdepth;
	int mono;
	int gray;
};
int oplus_display_panel_set_aod_area(void *buf);

int oplus_display_panel_get_aod_area(void *buf);

int oplus_display_panel_set_video(void *buf);

int oplus_display_panel_get_video(void *buf);
#endif /* OPLUS_FEATURE_AOD_RAMLESS */

int oplus_panel_update_backlight_unlock(struct dsi_panel *panel);

int oplus_set_display_vendor(struct dsi_display *display);

int oplus_dsi_update_spr_mode(void);

int oplus_dsi_update_seed_mode(void);

void oplus_panel_process_dimming_v2_post(struct dsi_panel *panel,
				bool force_disable);

int oplus_panel_process_dimming_v2(struct dsi_panel *panel, int bl_lvl,
				bool force_disable);

int oplus_panel_process_dimming_v3(struct dsi_panel *panel, int brightness);

bool is_dsi_panel(struct drm_crtc *crtc);

int interpolate(int x, int xa, int xb, int ya, int yb);

int dsi_display_oplus_set_power(struct drm_connector *connector, int power_mode,
				void *disp);

void lcdinfo_notify(unsigned long val, void *v);

int oplus_display_set_failsafe(void *buf);
int oplus_display_get_failsafe(void *buf);
int dsi_panel_switch_gamma_mode(struct dsi_panel *panel, u32 bl_lvl);

#endif /* _OPLUS_DISPLAY_PRIVATE_API_H_ */
