/* SPDX-License-Identifier: MIT */
/*
 * Copyright © 2025 Intel Corporation
 */

#ifndef _XE_SRIOV_VF_CCS_TYPES_H_
#define _XE_SRIOV_VF_CCS_TYPES_H_

#define for_each_ccs_rw_ctx(id__) \
	for ((id__) = 0; (id__) < XE_SRIOV_VF_CCS_CTX_COUNT; (id__)++)

enum xe_sriov_vf_ccs_rw_ctxs {
	XE_SRIOV_VF_CCS_READ_CTX,
	XE_SRIOV_VF_CCS_WRITE_CTX,
	XE_SRIOV_VF_CCS_CTX_COUNT
};

struct xe_migrate;
struct xe_sa_manager;

struct xe_tile_vf_ccs {
	/** @id: Id to which context it belongs to */
	enum xe_sriov_vf_ccs_rw_ctxs ctx_id;
	/** @mig_q: exec queues used for migration */
	struct xe_exec_queue *mig_q;

	struct {
		/** @ccs_bb_pool: Pool from which batch buffers are allocated. */
		struct xe_sa_manager *ccs_bb_pool;
	} mem;
};

#endif
