/** @file
 *  @brief Bluetooth Mesh Configuration Client Model APIs.
 */

/*
 * Copyright (c) 2017 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef __BT_MESH_CFG_CLI_H
#define __BT_MESH_CFG_CLI_H

/**
 * @brief Bluetooth Mesh
 * @defgroup bt_mesh_cfg_cli Bluetooth Mesh Configuration Client Model
 * @ingroup bt_mesh
 * @{
 */

/** Mesh Configuration Client Model Context */
struct bt_mesh_cfg_cli {
	struct bt_mesh_model *model;

	struct k_sem          op_sync;
	u32_t                 op_pending;
	void                 *op_param;
};

extern const struct bt_mesh_model_op bt_mesh_cfg_cli_op[];

#define BT_MESH_MODEL_CFG_CLI(cli_data)                                      \
		BT_MESH_MODEL(BT_MESH_MODEL_ID_CFG_CLI,                      \
			      bt_mesh_cfg_cli_op, NULL, cli_data)

int bt_mesh_cfg_comp_data_get(u16_t net_idx, u16_t addr, u8_t page,
			      u8_t *status, struct os_mbuf *comp);

int bt_mesh_cfg_beacon_get(u16_t net_idx, u16_t addr, u8_t *status);

int bt_mesh_cfg_beacon_set(u16_t net_idx, u16_t addr, u8_t val, u8_t *status);

int bt_mesh_cfg_ttl_get(u16_t net_idx, u16_t addr, u8_t *ttl);

int bt_mesh_cfg_ttl_set(u16_t net_idx, u16_t addr, u8_t val, u8_t *ttl);

int bt_mesh_cfg_friend_get(u16_t net_idx, u16_t addr, u8_t *status);

int bt_mesh_cfg_friend_set(u16_t net_idx, u16_t addr, u8_t val, u8_t *status);

int bt_mesh_cfg_gatt_proxy_get(u16_t net_idx, u16_t addr, u8_t *status);

int bt_mesh_cfg_gatt_proxy_set(u16_t net_idx, u16_t addr, u8_t val,
			       u8_t *status);

int bt_mesh_cfg_relay_get(u16_t net_idx, u16_t addr, u8_t *status,
			  u8_t *transmit);

int bt_mesh_cfg_relay_set(u16_t net_idx, u16_t addr, u8_t new_relay,
			  u8_t new_transmit, u8_t *status, u8_t *transmit);

int bt_mesh_cfg_app_key_add(u16_t net_idx, u16_t addr, u16_t key_net_idx,
			    u16_t key_app_idx, const u8_t app_key[16],
			    u8_t *status);

int bt_mesh_cfg_mod_app_bind(u16_t net_idx, u16_t addr, u16_t elem_addr,
			     u16_t mod_app_idx, u16_t mod_id, u8_t *status);

int bt_mesh_cfg_mod_app_bind_vnd(u16_t net_idx, u16_t addr, u16_t elem_addr,
				 u16_t mod_app_idx, u16_t mod_id, u16_t cid,
				 u8_t *status);

int bt_mesh_cfg_mod_sub_add(u16_t net_idx, u16_t addr, u16_t elem_addr,
			    u16_t sub_addr, u16_t mod_id, u8_t *status);

int bt_mesh_cfg_mod_sub_add_vnd(u16_t net_idx, u16_t addr, u16_t elem_addr,
				 u16_t sub_addr, u16_t mod_id, u16_t cid,
				 u8_t *status);

int bt_mesh_cfg_hb_sub_set(u16_t net_idx, u16_t addr, u16_t src, u16_t dst,
			   u8_t period, u8_t *status);

int bt_mesh_cfg_hb_pub_set(u16_t net_idx, u16_t addr, u16_t pub_dst,
			   u8_t count, u8_t period, u8_t ttl, u16_t feat,
			   u16_t pub_net_idx, u8_t *status);

int bt_mesh_cfg_hb_pub_get(u16_t net_idx, u16_t addr, u16_t *pub_dst,
			   u8_t *count, u8_t *period, u8_t *ttl, u16_t *feat,
			   u16_t *pub_net_idx, u8_t *status);

/**
 * @}
 */

#endif /* __BT_MESH_CFG_CLI_H */
