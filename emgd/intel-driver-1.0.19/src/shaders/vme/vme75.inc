/*
 * Copyright © <2010>, Intel Corporation.
 *
 * This program is licensed under the terms and conditions of the
 * Eclipse Public License (EPL), version 1.0.  The full text of the EPL is at
 * http://www.opensource.org/licenses/eclipse-1.0.php.
 *
 */
// Modual name: ME_header.inc
//
// Global symbols define
//

/*
 * Constant
 */
define(`VME_MESSAGE_TYPE_INTER',        `1')
define(`VME_MESSAGE_TYPE_INTRA',        `2')
define(`VME_MESSAGE_TYPE_MIXED',        `3')
        
define(`VME_SIC_MESSAGE_TYPE',        `1')
define(`VME_IME_MESSAGE_TYPE',        `2')
define(`VME_FBR_MESSAGE_TYPE',        `3')

define(`BLOCK_32X1',                    `0x0000001F')
define(`BLOCK_4X16',                    `0x000F0003')
define(`BLOCK_8X4',                     `0x00070003')
        
define(`LUMA_INTRA_16x16_DISABLE',      `0x1')
define(`LUMA_INTRA_8x8_DISABLE',        `0x2')
define(`LUMA_INTRA_4x4_DISABLE',        `0x4')

define(`INTRA_PRED_AVAIL_FLAG_AE',      `0x60')
define(`INTRA_PRED_AVAIL_FLAG_B',       `0x10')
define(`INTRA_PRED_AVAIL_FLAG_C',       `0x8')
define(`INTRA_PRED_AVAIL_FLAG_D',       `0x4')

define(`BIND_IDX_VME',                  `0')
define(`BIND_IDX_VME_REF0',             `1')
define(`BIND_IDX_VME_REF1',             `2')
define(`BIND_IDX_OUTPUT',               `3')
define(`BIND_IDX_INEP',                 `4')

define(`SUB_PEL_MODE_INTEGER',          `0x00000000')
define(`SUB_PEL_MODE_HALF',             `0x00001000')
define(`SUB_PEL_MODE_QUARTER',          `0x00003000')

define(`INTER_SAD_NONE',                `0x00000000')
define(`INTER_SAD_HAAR',                `0x00200000')

define(`INTRA_SAD_NONE',                `0x00000000')
define(`INTRA_SAD_HAAR',                `0x00800000')

define(`INTER_PART_MASK',               `0x00000000')

define(`SEARCH_CTRL_SINGLE',            `0x00000000')
define(`SEARCH_CTRL_DUAL_START',        `0x00000100')
define(`SEARCH_CTRL_DUAL_RECORD',       `0x00000300')
define(`SEARCH_CTRL_DUAL_REFERENCE',    `0x00000700')

define(`REF_REGION_SIZE',               `0x2830:UW')

define(`BI_SUB_MB_PART_MASK',           `0x0c000000')
define(`MAX_NUM_MV',                    `0x00000020')
define(`FB_PRUNING_ENABLE',             `0x40000000')

define(`SEARCH_PATH_LEN',               `0x00003030')
define(`START_CENTER',                  `0x30000000')

define(`ADAPTIVE_SEARCH_ENABLE',        `0x00000002') 
define(`INTRA_PREDICTORE_MODE',         `0x11111111:UD')

define(`INTER_VME_OUTPUT_IN_OWS',       `10')
define(`INTER_VME_OUTPUT_MV_IN_OWS',    `8')

define(`INTRAMBFLAG_MASK',              `0x00002000')
define(`MVSIZE_UW_BASE',                `0x0040')
define(`MFC_MV32_BIT_SHIFT',            `5')
define(`CBP_DC_YUV_UW',                 `0x000E')

define(`DC_HARR_ENABLE',                `0x0000')
define(`DC_HARR_DISABLE',		`0x0020')

define(`MV32_BIT_MASK',                 `0x0020')
define(`MV32_BIT_SHIFT',                `5')

define(`OBW_CACHE_TYPE',                `10')


define(`OBW_MESSAGE_TYPE',              `8')

define(`OBW_BIND_IDX',                  `BIND_IDX_OUTPUT')

define(`OBW_CONTROL_0',                 `0')    /* 1 OWord, low 128 bits */
define(`OBW_CONTROL_1',                 `1')    /* 1 OWord, high 128 bits */
define(`OBW_CONTROL_2',                 `2')    /* 2 OWords */
define(`OBW_CONTROL_3',                 `3')    /* 4 OWords */
define(`OBW_CONTROL_8',                 `4')    /* 8 OWords */

define(`FBR_BME_ENABLE',                 `0x00000000')
define(`FBR_BME_DISABLE',                `0x00040000')

define(`OBW_WRITE_COMMIT_CATEGORY',     `0')    /* category on Ivybridge */


define(`OBW_HEADER_PRESENT',            `1')

/* GRF registers
 * r0 header
 * r1~r4 constant buffer (reserved)
 * r5 inline data
 * r6~r11 reserved        
 * r12 write back of VME message
 * r13 write back of Oword Block Write        
 */
/*
 * GRF 0 -- header       
 */        
define(`thread_id_ub',          `r0.20<0,1,0>:UB')  /* thread id in payload */

/*
 * GRF 1~4 -- Constant Buffer (reserved)
 */
        
/*
 * GRF 5 -- inline data
 */        
define(`inline_reg0',           `r5')
define(`w_in_mb_uw',            `inline_reg0.2')
define(`orig_xy_ub',            `inline_reg0.0')
define(`orig_x_ub',             `inline_reg0.0')    /* in macroblock */    
define(`orig_y_ub',             `inline_reg0.1')
define(`transform_8x8_ub',      `inline_reg0.4')
define(`slice_edge_ub',         `inline_reg0.4')
define(`num_macroblocks',       `inline_reg0.6')
define(`input_mb_intra_ub',     `inline_reg0.5')

/*
 * GRF 6~11 -- reserved
 */

/*
 * GRF 12~15 -- write back for VME message 
 */
define(`vme_wb',                `r12')
define(`vme_wb0',               `r12')
define(`vme_wb1',               `r13')
define(`vme_wb2',               `r14')
define(`vme_wb3',               `r15')
define(`vme_wb4',               `r16')
define(`vme_wb5',               `r17')
define(`vme_wb6',               `r18')
define(`vme_ime_wb7',		`r19')
define(`vme_ime_wb8',		`r20')
define(`vme_ime_wb9',		`r21')
define(`vme_ime_wb10',		`r22')


/*
 * GRF 24 -- write for VME output message
 */
define(`obw_wb',                `null<1>:W')
define(`obw_wb_length',         `0')


/*
 * GRF 28~30 -- Intra Neighbor Edge Pixels
 */
define(`INEP_ROW',              `r28')
define(`INEP_COL0',             `r29')
define(`INEP_COL1',             `r30')
        
/*
 * GRF 48~50 -- Chroma Neighbor Edge Pixels
 */
define(`CHROMA_ROW',              `r48')
define(`CHROMA_COL',              `r49')

/*
 * temporary registers
 */
define(`tmp_reg0',              `r32')
define(`read0_header',          `tmp_reg0')
define(`tmp_reg1',              `r33')
define(`read1_header',          `tmp_reg1')
define(`tmp_reg2',              `r34')
define(`vme_m0',                `tmp_reg2')
define(`tmp_reg3',              `r35')                                
define(`vme_m1',                `tmp_reg3')
define(`intra_flag',            `vme_m1.28')
define(`intra_part_mask_ub',    `vme_m1.28')        
define(`mb_intra_struct_ub',    `vme_m1.29')
define(`tmp_reg4',              `r36')
define(`obw_m0',                `tmp_reg4')
define(`tmp_reg5',              `r37')
define(`obw_m1',                `tmp_reg5')
define(`tmp_reg6',              `r38')
define(`obw_m2',                `tmp_reg6')
define(`tmp_reg7',              `r39')
define(`obw_m3',                `tmp_reg7')
define(`tmp_reg8',              `r40')
define(`obw_m4',                `tmp_reg8')
define(`tmp_reg9',              `r41')
define(`tmp_x_w',               `tmp_reg9.0')
define(`tmp_rega',              `r42')
define(`tmp_ud0',               `tmp_rega.0')
define(`tmp_ud1',               `tmp_rega.4')
define(`tmp_ud2',               `tmp_rega.8')
define(`tmp_ud3',               `tmp_rega.12')
define(`tmp_uw0',               `tmp_rega.0')
define(`tmp_uw1',               `tmp_rega.2')
define(`tmp_uw2',               `tmp_rega.4')
define(`tmp_uw3',               `tmp_rega.6')
define(`tmp_uw4',               `tmp_rega.8')
define(`tmp_uw5',               `tmp_rega.10')
define(`tmp_uw6',               `tmp_rega.12')
define(`tmp_uw7',               `tmp_rega.14')

define(`vme_m2',                `r43')
/*
 * MRF registers
 */        

define(`msg_ind',               `64')
define(`msg_reg0',              `r64')
define(`msg_reg1',              `r65')
define(`msg_reg2',              `r66')
define(`msg_reg3',              `r67')
define(`msg_reg4',              `r68')
define(`msg_reg5',              `r69')
define(`msg_reg6',              `r70')
define(`msg_reg7',              `r71')
define(`msg_reg8',              `r72')
define(`msg_reg9',              `r73')

define(`ts_msg_ind',               `112')
define(`ts_msg_reg0',               `r112')
/*
 * VME message payload
 */

define(`vme_intra_wb_length',   `1')
define(`vme_wb_length',		`7')
define(`sic_vme_msg_length',	`7')
define(`fbr_vme_msg_length',	`7')
define(`ime_vme_msg_length',	`5')

define(`vme_msg_ind',           `msg_ind')
define(`vme_msg_0',             `msg_reg0')
define(`vme_msg_1',             `msg_reg1')
define(`vme_msg_2',             `msg_reg2')

define(`vme_msg_3',             `msg_reg3')
define(`vme_msg_4',             `msg_reg4')


define(`vme_msg_5',             `msg_reg5')
define(`vme_msg_6',             `msg_reg6')
define(`vme_msg_7',             `msg_reg7')
define(`vme_msg_8',             `msg_reg8')
define(`vme_msg_9',             `msg_reg9')

define(`BIND_IDX_CBCR',			`6')


define(`LUMA_CHROMA_MODE',      `0x0')
define(`LUMA_INTRA_MODE',	`0x1')
define(`LUMA_INTRA_DISABLE',	`0x2')
