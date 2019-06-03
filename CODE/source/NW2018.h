//	[VERSION] 1.0, 3
// Do not modify manually.

#ifndef _NW2018_H_
#define _NW2018_H_

#ifndef __DISABLE_HGCC_BUILD_IN__
#include "build-in.h"
#endif

#define DEFINE_ISR(isr_name, vector) void __attribute((interrupt(vector))) isr_name(void)

#define DEFINE_SFR(sfr_type, sfr, addr) static volatile sfr_type sfr __attribute__ ((at(addr)))

typedef unsigned char __sfr_byte;

typedef struct {
	unsigned char __c : 1;
	unsigned char __ac : 1;
	unsigned char __z : 1;
	unsigned char __ov : 1;
	unsigned char __pdf : 1;
	unsigned char __to : 1;
	unsigned char __cz : 1;
	unsigned char __sc : 1;
} __status_bits;

typedef union {
	__status_bits bits;
	__sfr_byte byte;
} __status_type;

typedef struct {
	unsigned char __fsiden : 1;
	unsigned char __fhiden : 1;
	unsigned char : 3;
	unsigned char __cks0 : 1;
	unsigned char __cks1 : 1;
	unsigned char __cks2 : 1;
} __scc_bits;

typedef union {
	__scc_bits bits;
	__sfr_byte byte;
} __scc_type;

typedef struct {
	unsigned char __emi : 1;
	unsigned char __int0e : 1;
	unsigned char __cp0e : 1;
	unsigned char __cp1e : 1;
	unsigned char __int0f : 1;
	unsigned char __cp0f : 1;
	unsigned char __cp1f : 1;
	unsigned char : 1;
} __intc0_bits;

typedef union {
	__intc0_bits bits;
	__sfr_byte byte;
} __intc0_type;

typedef struct {
	unsigned char __cp2e : 1;
	unsigned char __cp3e : 1;
	unsigned char __cp4e : 1;
	unsigned char __synce : 1;
	unsigned char __cp2f : 1;
	unsigned char __cp3f : 1;
	unsigned char __cp4f : 1;
	unsigned char __syncf : 1;
} __intc1_bits;

typedef union {
	__intc1_bits bits;
	__sfr_byte byte;
} __intc1_type;

typedef struct {
	unsigned char __iice : 1;
	unsigned char __mf0e : 1;
	unsigned char __tb1e : 1;
	unsigned char __te : 1;
	unsigned char __iicf : 1;
	unsigned char __mf0f : 1;
	unsigned char __tb1f : 1;
	unsigned char __tf : 1;
} __intc2_bits;

typedef union {
	__intc2_bits bits;
	__sfr_byte byte;
} __intc2_type;

typedef struct {
	unsigned char __ur0e : 1;
	unsigned char __mf1e : 1;
	unsigned char __mf2e : 1;
	unsigned char __mf3e : 1;
	unsigned char __ur0f : 1;
	unsigned char __mf1f : 1;
	unsigned char __mf2f : 1;
	unsigned char __mf3f : 1;
} __intc3_bits;

typedef union {
	__intc3_bits bits;
	__sfr_byte byte;
} __intc3_type;

typedef struct {
	unsigned char __pa0 : 1;
	unsigned char __pa1 : 1;
	unsigned char __pa2 : 1;
	unsigned char __pa3 : 1;
	unsigned char __pa4 : 1;
	unsigned char __pa5 : 1;
	unsigned char __pa6 : 1;
	unsigned char __pa7 : 1;
} __pa_bits;

typedef union {
	__pa_bits bits;
	__sfr_byte byte;
} __pa_type;

typedef struct {
	unsigned char __pac0 : 1;
	unsigned char __pac1 : 1;
	unsigned char __pac2 : 1;
	unsigned char __pac3 : 1;
	unsigned char __pac4 : 1;
	unsigned char __pac5 : 1;
	unsigned char __pac6 : 1;
	unsigned char __pac7 : 1;
} __pac_bits;

typedef union {
	__pac_bits bits;
	__sfr_byte byte;
} __pac_type;

typedef struct {
	unsigned char __papu0 : 1;
	unsigned char __papu1 : 1;
	unsigned char __papu2 : 1;
	unsigned char __papu3 : 1;
	unsigned char __papu4 : 1;
	unsigned char __papu5 : 1;
	unsigned char __papu6 : 1;
	unsigned char __papu7 : 1;
} __papu_bits;

typedef union {
	__papu_bits bits;
	__sfr_byte byte;
} __papu_type;

typedef struct {
	unsigned char __pawu0 : 1;
	unsigned char __pawu1 : 1;
	unsigned char __pawu2 : 1;
	unsigned char __pawu3 : 1;
	unsigned char __pawu4 : 1;
	unsigned char __pawu5 : 1;
	unsigned char __pawu6 : 1;
	unsigned char __pawu7 : 1;
} __pawu_bits;

typedef union {
	__pawu_bits bits;
	__sfr_byte byte;
} __pawu_type;

typedef struct {
	unsigned char __ptm0pe : 1;
	unsigned char __ptm0ae : 1;
	unsigned char __tb0e : 1;
	unsigned char : 1;
	unsigned char __ptm0pf : 1;
	unsigned char __ptm0af : 1;
	unsigned char __tb0f : 1;
	unsigned char : 1;
} __mfi0_bits;

typedef union {
	__mfi0_bits bits;
	__sfr_byte byte;
} __mfi0_type;

typedef struct {
	unsigned char __ctm0pe : 1;
	unsigned char __ctm0ae : 1;
	unsigned char __ade : 1;
	unsigned char : 1;
	unsigned char __ctm0pf : 1;
	unsigned char __ctm0af : 1;
	unsigned char __adf : 1;
	unsigned char : 1;
} __mfi1_bits;

typedef union {
	__mfi1_bits bits;
	__sfr_byte byte;
} __mfi1_type;

typedef struct {
	unsigned char __ctm1pe : 1;
	unsigned char __ctm1ae : 1;
	unsigned char __dee : 1;
	unsigned char : 1;
	unsigned char __ctm1pf : 1;
	unsigned char __ctm1af : 1;
	unsigned char __def : 1;
	unsigned char : 1;
} __mfi2_bits;

typedef union {
	__mfi2_bits bits;
	__sfr_byte byte;
} __mfi2_type;

typedef struct {
	unsigned char __int1e : 1;
	unsigned char __lve : 1;
	unsigned char : 2;
	unsigned char __int1f : 1;
	unsigned char __lvf : 1;
	unsigned char : 2;
} __mfi3_bits;

typedef union {
	__mfi3_bits bits;
	__sfr_byte byte;
} __mfi3_type;

typedef struct {
	unsigned char __ws0 : 1;
	unsigned char __ws1 : 1;
	unsigned char __ws2 : 1;
	unsigned char __we0 : 1;
	unsigned char __we1 : 1;
	unsigned char __we2 : 1;
	unsigned char __we3 : 1;
	unsigned char __we4 : 1;
} __wdtc_bits;

typedef union {
	__wdtc_bits bits;
	__sfr_byte byte;
} __wdtc_type;

typedef struct {
	unsigned char __wrf : 1;
	unsigned char __lrf : 1;
	unsigned char __lvrf : 1;
	unsigned char : 5;
} __rstfc_bits;

typedef union {
	__rstfc_bits bits;
	__sfr_byte byte;
} __rstfc_type;

typedef struct {
	unsigned char __lvs0 : 1;
	unsigned char __lvs1 : 1;
	unsigned char __lvs2 : 1;
	unsigned char __lvs3 : 1;
	unsigned char __lvs4 : 1;
	unsigned char __lvs5 : 1;
	unsigned char __lvs6 : 1;
	unsigned char __lvs7 : 1;
} __lvrc_bits;

typedef union {
	__lvrc_bits bits;
	__sfr_byte byte;
} __lvrc_type;

typedef struct {
	unsigned char __vlvd0 : 1;
	unsigned char __vlvd1 : 1;
	unsigned char __vlvd2 : 1;
	unsigned char __vbgen : 1;
	unsigned char __lvden : 1;
	unsigned char __lvdo : 1;
	unsigned char : 2;
} __lvdc_bits;

typedef union {
	__lvdc_bits bits;
	__sfr_byte byte;
} __lvdc_type;

typedef struct {
	unsigned char __int0s0 : 1;
	unsigned char __int0s1 : 1;
	unsigned char __int1s0 : 1;
	unsigned char __int1s1 : 1;
	unsigned char : 4;
} __integ_bits;

typedef union {
	__integ_bits bits;
	__sfr_byte byte;
} __integ_type;

typedef struct {
	unsigned char __tb00 : 1;
	unsigned char __tb01 : 1;
	unsigned char __tb02 : 1;
	unsigned char : 1;
	unsigned char __tb10 : 1;
	unsigned char __tb11 : 1;
	unsigned char __tbck : 1;
	unsigned char __tbon : 1;
} __tbc_bits;

typedef union {
	__tbc_bits bits;
	__sfr_byte byte;
} __tbc_type;

typedef struct {
	unsigned char __pc0 : 1;
	unsigned char __pc1 : 1;
	unsigned char __pc2 : 1;
	unsigned char __pc3 : 1;
	unsigned char __pc4 : 1;
	unsigned char : 3;
} __pc_bits;

typedef union {
	__pc_bits bits;
	__sfr_byte byte;
} __pc_type;

typedef struct {
	unsigned char __pcc0 : 1;
	unsigned char __pcc1 : 1;
	unsigned char __pcc2 : 1;
	unsigned char __pcc3 : 1;
	unsigned char __pcc4 : 1;
	unsigned char : 3;
} __pcc_bits;

typedef union {
	__pcc_bits bits;
	__sfr_byte byte;
} __pcc_type;

typedef struct {
	unsigned char __pcpu0 : 1;
	unsigned char __pcpu1 : 1;
	unsigned char __pcpu2 : 1;
	unsigned char __pcpu3 : 1;
	unsigned char __pcpu4 : 1;
	unsigned char : 3;
} __pcpu_bits;

typedef union {
	__pcpu_bits bits;
	__sfr_byte byte;
} __pcpu_type;

typedef struct {
	unsigned char __ct0rp0 : 1;
	unsigned char __ct0rp1 : 1;
	unsigned char __ct0rp2 : 1;
	unsigned char __ct0on : 1;
	unsigned char __ct0ck0 : 1;
	unsigned char __ct0ck1 : 1;
	unsigned char __ct0ck2 : 1;
	unsigned char __ct0pau : 1;
} __ctm0c0_bits;

typedef union {
	__ctm0c0_bits bits;
	__sfr_byte byte;
} __ctm0c0_type;

typedef struct {
	unsigned char __ct0cclr : 1;
	unsigned char __ct0dpx : 1;
	unsigned char __ct0pol : 1;
	unsigned char __ct0oc : 1;
	unsigned char __ct0io0 : 1;
	unsigned char __ct0io1 : 1;
	unsigned char __ct0m0 : 1;
	unsigned char __ct0m1 : 1;
} __ctm0c1_bits;

typedef union {
	__ctm0c1_bits bits;
	__sfr_byte byte;
} __ctm0c1_type;

typedef struct {
	unsigned char : 3;
	unsigned char __pt0on : 1;
	unsigned char __pt0ck0 : 1;
	unsigned char __pt0ck1 : 1;
	unsigned char __pt0ck2 : 1;
	unsigned char __pt0pau : 1;
} __ptm0c0_bits;

typedef union {
	__ptm0c0_bits bits;
	__sfr_byte byte;
} __ptm0c0_type;

typedef struct {
	unsigned char __pt0cclr : 1;
	unsigned char __pt0capts : 1;
	unsigned char __pt0pol : 1;
	unsigned char __pt0oc : 1;
	unsigned char __pt0io0 : 1;
	unsigned char __pt0io1 : 1;
	unsigned char __pt0m0 : 1;
	unsigned char __pt0m1 : 1;
} __ptm0c1_bits;

typedef union {
	__ptm0c1_bits bits;
	__sfr_byte byte;
} __ptm0c1_type;

typedef struct {
	unsigned char : 1;
	unsigned char __iicen : 1;
	unsigned char __iicdeb0 : 1;
	unsigned char __iicdeb1 : 1;
	unsigned char : 4;
} __iicc0_bits;

typedef union {
	__iicc0_bits bits;
	__sfr_byte byte;
} __iicc0_type;

typedef struct {
	unsigned char __rxak : 1;
	unsigned char __iamwu : 1;
	unsigned char __srw : 1;
	unsigned char __txak : 1;
	unsigned char __htx : 1;
	unsigned char __hbb : 1;
	unsigned char __haas : 1;
	unsigned char __hcf : 1;
} __iicc1_bits;

typedef union {
	__iicc1_bits bits;
	__sfr_byte byte;
} __iicc1_type;

typedef struct {
	unsigned char : 1;
	unsigned char __a0 : 1;
	unsigned char __a1 : 1;
	unsigned char __a2 : 1;
	unsigned char __a3 : 1;
	unsigned char __a4 : 1;
	unsigned char __a5 : 1;
	unsigned char __a6 : 1;
} __iica_bits;

typedef union {
	__iica_bits bits;
	__sfr_byte byte;
} __iica_type;

typedef struct {
	unsigned char __iictos0 : 1;
	unsigned char __iictos1 : 1;
	unsigned char __iictos2 : 1;
	unsigned char __iictos3 : 1;
	unsigned char __iictos4 : 1;
	unsigned char __iictos5 : 1;
	unsigned char __iictof : 1;
	unsigned char __iictoen : 1;
} __iictoc_bits;

typedef union {
	__iictoc_bits bits;
	__sfr_byte byte;
} __iictoc_type;

typedef struct {
	unsigned char __sacs0 : 1;
	unsigned char __sacs1 : 1;
	unsigned char __sacs2 : 1;
	unsigned char __sacs3 : 1;
	unsigned char __adrfs : 1;
	unsigned char __adcen : 1;
	unsigned char __adbz : 1;
	unsigned char __start : 1;
} __sadc0_bits;

typedef union {
	__sadc0_bits bits;
	__sfr_byte byte;
} __sadc0_type;

typedef struct {
	unsigned char __sacks0 : 1;
	unsigned char __sacks1 : 1;
	unsigned char __sacks2 : 1;
	unsigned char : 1;
	unsigned char __sains0 : 1;
	unsigned char __sains1 : 1;
	unsigned char __sains2 : 1;
	unsigned char __sains3 : 1;
} __sadc1_bits;

typedef union {
	__sadc1_bits bits;
	__sfr_byte byte;
} __sadc1_type;

typedef struct {
	unsigned char __pgags0 : 1;
	unsigned char __pgags1 : 1;
	unsigned char __savrs0 : 1;
	unsigned char __savrs1 : 1;
	unsigned char __pgais : 1;
	unsigned char __verify0 : 1;
	unsigned char : 1;
	unsigned char __adpgaen : 1;
} __sadc2_bits;

typedef union {
	__sadc2_bits bits;
	__sfr_byte byte;
} __sadc2_type;

typedef struct {
	unsigned char __pb0 : 1;
	unsigned char __pb1 : 1;
	unsigned char __pb2 : 1;
	unsigned char __pb3 : 1;
	unsigned char : 4;
} __pb_bits;

typedef union {
	__pb_bits bits;
	__sfr_byte byte;
} __pb_type;

typedef struct {
	unsigned char __pbc0 : 1;
	unsigned char __pbc1 : 1;
	unsigned char __pbc2 : 1;
	unsigned char __pbc3 : 1;
	unsigned char : 4;
} __pbc_bits;

typedef union {
	__pbc_bits bits;
	__sfr_byte byte;
} __pbc_type;

typedef struct {
	unsigned char __pbpu0 : 1;
	unsigned char __pbpu1 : 1;
	unsigned char __pbpu2 : 1;
	unsigned char __pbpu3 : 1;
	unsigned char : 4;
} __pbpu_bits;

typedef union {
	__pbpu_bits bits;
	__sfr_byte byte;
} __pbpu_type;

typedef struct {
	unsigned char __pbs00 : 1;
	unsigned char __pbs01 : 1;
	unsigned char __pbs02 : 1;
	unsigned char __pbs03 : 1;
	unsigned char : 4;
} __pbs0_bits;

typedef union {
	__pbs0_bits bits;
	__sfr_byte byte;
} __pbs0_type;

typedef struct {
	unsigned char __pcsd : 1;
	unsigned char __trgmod : 1;
	unsigned char : 1;
	unsigned char __ptsyn : 1;
	unsigned char __rlbf : 1;
	unsigned char : 1;
	unsigned char __prsen : 1;
	unsigned char __pst : 1;
} __ppgc_bits;

typedef union {
	__ppgc_bits bits;
	__sfr_byte byte;
} __ppgc_type;

typedef struct {
	unsigned char __ppgpc0 : 1;
	unsigned char __ppgpc1 : 1;
	unsigned char __ppgpc2 : 1;
	unsigned char __ppgpc3 : 1;
	unsigned char __ppgpc4 : 1;
	unsigned char __ppgpc5 : 1;
	unsigned char __ppgpc6 : 1;
	unsigned char __ppgpc7 : 1;
} __ppgpc_bits;

typedef union {
	__ppgpc_bits bits;
	__sfr_byte byte;
} __ppgpc_type;

typedef struct {
	unsigned char __ppgta0 : 1;
	unsigned char __ppgta1 : 1;
	unsigned char __ppgta2 : 1;
	unsigned char __ppgta3 : 1;
	unsigned char __ppgta4 : 1;
	unsigned char __ppgta5 : 1;
	unsigned char __ppgta6 : 1;
	unsigned char __ppgta7 : 1;
} __ppgta_bits;

typedef union {
	__ppgta_bits bits;
	__sfr_byte byte;
} __ppgta_type;

typedef struct {
	unsigned char __ppgtb0 : 1;
	unsigned char __ppgtb1 : 1;
	unsigned char __ppgtb2 : 1;
	unsigned char __ppgtb3 : 1;
	unsigned char __ppgtb4 : 1;
	unsigned char __ppgtb5 : 1;
	unsigned char __ppgtb6 : 1;
	unsigned char __ppgtb7 : 1;
} __ppgtb_bits;

typedef union {
	__ppgtb_bits bits;
	__sfr_byte byte;
} __ppgtb_type;

typedef struct {
	unsigned char __ppgta8 : 1;
	unsigned char : 3;
	unsigned char __ppgtb8 : 1;
	unsigned char : 3;
} __ppgtex_bits;

typedef union {
	__ppgtex_bits bits;
	__sfr_byte byte;
} __ppgtex_type;

typedef struct {
	unsigned char __tdps0 : 1;
	unsigned char __tdps1 : 1;
	unsigned char __tdugs0 : 1;
	unsigned char __tdugs1 : 1;
	unsigned char __tdccs0 : 1;
	unsigned char __tdccs1 : 1;
	unsigned char __tdcce : 1;
	unsigned char __tduge : 1;
} __tdc_bits;

typedef union {
	__tdc_bits bits;
	__sfr_byte byte;
} __tdc_type;

typedef struct {
	unsigned char __ct1rp0 : 1;
	unsigned char __ct1rp1 : 1;
	unsigned char __ct1rp2 : 1;
	unsigned char __ct1on : 1;
	unsigned char __ct1ck0 : 1;
	unsigned char __ct1ck1 : 1;
	unsigned char __ct1ck2 : 1;
	unsigned char __ct1pau : 1;
} __ctm1c0_bits;

typedef union {
	__ctm1c0_bits bits;
	__sfr_byte byte;
} __ctm1c0_type;

typedef struct {
	unsigned char __ct1cclr : 1;
	unsigned char __ct1dpx : 1;
	unsigned char __ct1pol : 1;
	unsigned char __ct1oc : 1;
	unsigned char __ct1io0 : 1;
	unsigned char __ct1io1 : 1;
	unsigned char __ct1m0 : 1;
	unsigned char __ct1m1 : 1;
} __ctm1c1_bits;

typedef union {
	__ctm1c1_bits bits;
	__sfr_byte byte;
} __ctm1c1_type;

typedef struct {
	unsigned char __txif0 : 1;
	unsigned char __tidle0 : 1;
	unsigned char __rxif0 : 1;
	unsigned char __ridle0 : 1;
	unsigned char __oerr0 : 1;
	unsigned char __ferr0 : 1;
	unsigned char __nf0 : 1;
	unsigned char __perr0 : 1;
} __u0sr_bits;

typedef union {
	__u0sr_bits bits;
	__sfr_byte byte;
} __u0sr_type;

typedef struct {
	unsigned char __tx80 : 1;
	unsigned char __rx80 : 1;
	unsigned char __txbrk0 : 1;
	unsigned char __stops0 : 1;
	unsigned char __prt0 : 1;
	unsigned char __pren0 : 1;
	unsigned char __bno0 : 1;
	unsigned char __uarten0 : 1;
} __u0cr1_bits;

typedef union {
	__u0cr1_bits bits;
	__sfr_byte byte;
} __u0cr1_type;

typedef struct {
	unsigned char __teie0 : 1;
	unsigned char __tiie0 : 1;
	unsigned char __rie0 : 1;
	unsigned char __wake0 : 1;
	unsigned char __adden0 : 1;
	unsigned char __brgh0 : 1;
	unsigned char __rxen0 : 1;
	unsigned char __txen0 : 1;
} __u0cr2_bits;

typedef union {
	__u0cr2_bits bits;
	__sfr_byte byte;
} __u0cr2_type;

typedef struct {
	unsigned char __cts0 : 1;
	unsigned char __cts1 : 1;
	unsigned char __cton : 1;
	unsigned char __ovf : 1;
	unsigned char : 4;
} __ppgctc_bits;

typedef union {
	__ppgctc_bits bits;
	__sfr_byte byte;
} __ppgctc_type;

typedef struct {
	unsigned char __pckpsc0 : 1;
	unsigned char __pckpsc1 : 1;
	unsigned char __pckpsc2 : 1;
	unsigned char __pckpsc3 : 1;
	unsigned char __pcken : 1;
	unsigned char __pckpol : 1;
	unsigned char __pckd : 1;
	unsigned char : 1;
} __pckc_bits;

typedef union {
	__pckc_bits bits;
	__sfr_byte byte;
} __pckc_type;

typedef struct {
	unsigned char : 3;
	unsigned char __sdapc : 1;
	unsigned char __sclpc : 1;
	unsigned char __rxpc : 1;
	unsigned char __tdccs2 : 1;
	unsigned char : 1;
} __ctrl_bits;

typedef union {
	__ctrl_bits bits;
	__sfr_byte byte;
} __ctrl_type;

typedef struct {
	unsigned char __pcs00 : 1;
	unsigned char __pcs01 : 1;
	unsigned char __pcs02 : 1;
	unsigned char __pcs03 : 1;
	unsigned char __pcs04 : 1;
	unsigned char __pcs05 : 1;
	unsigned char __pcs06 : 1;
	unsigned char __pcs07 : 1;
} __pcs0_bits;

typedef union {
	__pcs0_bits bits;
	__sfr_byte byte;
} __pcs0_type;

typedef struct {
	unsigned char __pcs10 : 1;
	unsigned char __pcs11 : 1;
	unsigned char : 6;
} __pcs1_bits;

typedef union {
	__pcs1_bits bits;
	__sfr_byte byte;
} __pcs1_type;

typedef struct {
	unsigned char : 6;
	unsigned char __c1eg0 : 1;
	unsigned char __c1eg1 : 1;
} __cmp1c2_bits;

typedef union {
	__cmp1c2_bits bits;
	__sfr_byte byte;
} __cmp1c2_type;

typedef struct {
	unsigned char : 6;
	unsigned char __c3eg0 : 1;
	unsigned char __c3eg1 : 1;
} __cmp3c2_bits;

typedef union {
	__cmp3c2_bits bits;
	__sfr_byte byte;
} __cmp3c2_type;

typedef struct {
	unsigned char : 1;
	unsigned char __c0csw : 1;
	unsigned char __c0rsw : 1;
	unsigned char __c0o : 1;
	unsigned char __c0chy : 1;
	unsigned char __c0en : 1;
	unsigned char __c0eg0 : 1;
	unsigned char __c0eg1 : 1;
} __cmp0c0_bits;

typedef union {
	__cmp0c0_bits bits;
	__sfr_byte byte;
} __cmp0c0_type;

typedef struct {
	unsigned char __c0of0 : 1;
	unsigned char __c0of1 : 1;
	unsigned char __c0of2 : 1;
	unsigned char __c0of3 : 1;
	unsigned char __c0of4 : 1;
	unsigned char __c0rs : 1;
	unsigned char __c0ofm : 1;
	unsigned char __c0cx : 1;
} __cmp0c1_bits;

typedef union {
	__cmp0c1_bits bits;
	__sfr_byte byte;
} __cmp0c1_type;

typedef struct {
	unsigned char __c0db0 : 1;
	unsigned char __c0db1 : 1;
	unsigned char __c0db2 : 1;
	unsigned char __c0db3 : 1;
	unsigned char __c0db4 : 1;
	unsigned char __c0db5 : 1;
	unsigned char : 2;
} __cmp0c2_bits;

typedef union {
	__cmp0c2_bits bits;
	__sfr_byte byte;
} __cmp0c2_type;

typedef struct {
	unsigned char __ppgdl0 : 1;
	unsigned char __ppgdl1 : 1;
	unsigned char __ppgdl2 : 1;
	unsigned char __ppgdl3 : 1;
	unsigned char __ppgdl4 : 1;
	unsigned char __ppgdl5 : 1;
	unsigned char : 2;
} __cmp0c3_bits;

typedef union {
	__cmp0c3_bits bits;
	__sfr_byte byte;
} __cmp0c3_type;

typedef struct {
	unsigned char __hircen : 1;
	unsigned char __hircf : 1;
	unsigned char : 6;
} __hircc_bits;

typedef union {
	__hircc_bits bits;
	__sfr_byte byte;
} __hircc_type;

typedef struct {
	unsigned char __c1db0 : 1;
	unsigned char __c1db1 : 1;
	unsigned char __c1rv : 1;
	unsigned char __c1o : 1;
	unsigned char __c1chy : 1;
	unsigned char __c1en : 1;
	unsigned char __c1rlen : 1;
	unsigned char __pspc1e : 1;
} __cmp1c0_bits;

typedef union {
	__cmp1c0_bits bits;
	__sfr_byte byte;
} __cmp1c0_type;

typedef struct {
	unsigned char __c1of0 : 1;
	unsigned char __c1of1 : 1;
	unsigned char __c1of2 : 1;
	unsigned char __c1of3 : 1;
	unsigned char __c1of4 : 1;
	unsigned char __c1rs : 1;
	unsigned char __c1ofm : 1;
	unsigned char __c1cx : 1;
} __cmp1c1_bits;

typedef union {
	__cmp1c1_bits bits;
	__sfr_byte byte;
} __cmp1c1_type;

typedef struct {
	unsigned char __c2db0 : 1;
	unsigned char __c2db1 : 1;
	unsigned char __c2rv : 1;
	unsigned char __c2o : 1;
	unsigned char __c2chy : 1;
	unsigned char __c2en : 1;
	unsigned char __c2eg0 : 1;
	unsigned char __c2eg1 : 1;
} __cmp2c0_bits;

typedef union {
	__cmp2c0_bits bits;
	__sfr_byte byte;
} __cmp2c0_type;

typedef struct {
	unsigned char __c2of0 : 1;
	unsigned char __c2of1 : 1;
	unsigned char __c2of2 : 1;
	unsigned char __c2of3 : 1;
	unsigned char __c2of4 : 1;
	unsigned char __c2rs : 1;
	unsigned char __c2ofm : 1;
	unsigned char __c2cx : 1;
} __cmp2c1_bits;

typedef union {
	__cmp2c1_bits bits;
	__sfr_byte byte;
} __cmp2c1_type;

typedef struct {
	unsigned char __c3db0 : 1;
	unsigned char __c3db1 : 1;
	unsigned char __c3rv : 1;
	unsigned char __c3o : 1;
	unsigned char __c3chy : 1;
	unsigned char __c3en : 1;
	unsigned char : 1;
	unsigned char __pspc3e : 1;
} __cmp3c0_bits;

typedef union {
	__cmp3c0_bits bits;
	__sfr_byte byte;
} __cmp3c0_type;

typedef struct {
	unsigned char __c3of0 : 1;
	unsigned char __c3of1 : 1;
	unsigned char __c3of2 : 1;
	unsigned char __c3of3 : 1;
	unsigned char __c3of4 : 1;
	unsigned char __c3rs : 1;
	unsigned char __c3ofm : 1;
	unsigned char __c3cx : 1;
} __cmp3c1_bits;

typedef union {
	__cmp3c1_bits bits;
	__sfr_byte byte;
} __cmp3c1_type;

typedef struct {
	unsigned char __c4db0 : 1;
	unsigned char __c4db1 : 1;
	unsigned char __c4rv : 1;
	unsigned char __c4o : 1;
	unsigned char __c4chy : 1;
	unsigned char __c4en : 1;
	unsigned char __c4rlen : 1;
	unsigned char __pspc4e : 1;
} __cmp4c0_bits;

typedef union {
	__cmp4c0_bits bits;
	__sfr_byte byte;
} __cmp4c0_type;

typedef struct {
	unsigned char __c4of0 : 1;
	unsigned char __c4of1 : 1;
	unsigned char __c4of2 : 1;
	unsigned char __c4of3 : 1;
	unsigned char __c4of4 : 1;
	unsigned char __c4rs : 1;
	unsigned char __c4ofm : 1;
	unsigned char __c4cx : 1;
} __cmp4c1_bits;

typedef union {
	__cmp4c1_bits bits;
	__sfr_byte byte;
} __cmp4c1_type;

typedef struct {
	unsigned char __c4pc0 : 1;
	unsigned char __c4pc1 : 1;
	unsigned char : 4;
	unsigned char __c4eg0 : 1;
	unsigned char __c4eg1 : 1;
} __cmp4c2_bits;

typedef union {
	__cmp4c2_bits bits;
	__sfr_byte byte;
} __cmp4c2_type;

typedef struct {
	unsigned char __opax : 1;
	unsigned char __swr1 : 1;
	unsigned char __swr2 : 1;
	unsigned char __opag0 : 1;
	unsigned char __opag1 : 1;
	unsigned char __opag2 : 1;
	unsigned char __opam0 : 1;
	unsigned char __opam1 : 1;
} __opac0_bits;

typedef union {
	__opac0_bits bits;
	__sfr_byte byte;
} __opac0_type;

typedef struct {
	unsigned char __aof0 : 1;
	unsigned char __aof1 : 1;
	unsigned char __aof2 : 1;
	unsigned char __aof3 : 1;
	unsigned char __aof4 : 1;
	unsigned char __aof5 : 1;
	unsigned char __ars : 1;
	unsigned char __aofm : 1;
} __opac1_bits;

typedef union {
	__opac1_bits bits;
	__sfr_byte byte;
} __opac1_type;

typedef struct {
	unsigned char __pas00 : 1;
	unsigned char __pas01 : 1;
	unsigned char __pas02 : 1;
	unsigned char __pas03 : 1;
	unsigned char __pas04 : 1;
	unsigned char __pas05 : 1;
	unsigned char __pas06 : 1;
	unsigned char __pas07 : 1;
} __pas0_bits;

typedef union {
	__pas0_bits bits;
	__sfr_byte byte;
} __pas0_type;

typedef struct {
	unsigned char __pas10 : 1;
	unsigned char __pas11 : 1;
	unsigned char __pas12 : 1;
	unsigned char __pas13 : 1;
	unsigned char __pas14 : 1;
	unsigned char __pas15 : 1;
	unsigned char __pas16 : 1;
	unsigned char __pas17 : 1;
} __pas1_bits;

typedef union {
	__pas1_bits bits;
	__sfr_byte byte;
} __pas1_type;

typedef struct {
	unsigned char __tpsc0 : 1;
	unsigned char __tpsc1 : 1;
	unsigned char __tpsc2 : 1;
	unsigned char : 1;
	unsigned char __ton : 1;
	unsigned char : 1;
	unsigned char __tm0 : 1;
	unsigned char __tm1 : 1;
} __tmrc_bits;

typedef union {
	__tmrc_bits bits;
	__sfr_byte byte;
} __tmrc_type;

typedef struct {
	unsigned char __rd : 1;
	unsigned char __rden : 1;
	unsigned char __wr : 1;
	unsigned char __wren : 1;
	unsigned char : 4;
} __eec_bits;

typedef union {
	__eec_bits bits;
	__sfr_byte byte;
} __eec_type;


DEFINE_SFR(__sfr_byte, __mp0, 0x01);
DEFINE_SFR(__sfr_byte, __mp1l, 0x03);
DEFINE_SFR(__sfr_byte, __mp1h, 0x04);
DEFINE_SFR(__sfr_byte, __acc, 0x05);
DEFINE_SFR(__sfr_byte, __pcl, 0x06);
DEFINE_SFR(__sfr_byte, __tblp, 0x07);
DEFINE_SFR(__sfr_byte, __tblh, 0x08);
DEFINE_SFR(__sfr_byte, __tbhp, 0x09);
DEFINE_SFR(__status_type, __status, 0x0a);
DEFINE_SFR(__sfr_byte, __mp2l, 0x0d);
DEFINE_SFR(__sfr_byte, __mp2h, 0x0e);
DEFINE_SFR(__scc_type, __scc, 0x0f);
DEFINE_SFR(__intc0_type, __intc0, 0x10);
DEFINE_SFR(__intc1_type, __intc1, 0x11);
DEFINE_SFR(__intc2_type, __intc2, 0x12);
DEFINE_SFR(__intc3_type, __intc3, 0x13);
DEFINE_SFR(__pa_type, __pa, 0x14);
DEFINE_SFR(__pac_type, __pac, 0x15);
DEFINE_SFR(__papu_type, __papu, 0x16);
DEFINE_SFR(__pawu_type, __pawu, 0x17);
DEFINE_SFR(__mfi0_type, __mfi0, 0x18);
DEFINE_SFR(__mfi1_type, __mfi1, 0x1c);
DEFINE_SFR(__mfi2_type, __mfi2, 0x1d);
DEFINE_SFR(__mfi3_type, __mfi3, 0x1e);
DEFINE_SFR(__wdtc_type, __wdtc, 0x1f);
DEFINE_SFR(__rstfc_type, __rstfc, 0x20);
DEFINE_SFR(__lvrc_type, __lvrc, 0x21);
DEFINE_SFR(__lvdc_type, __lvdc, 0x22);
DEFINE_SFR(__integ_type, __integ, 0x23);
DEFINE_SFR(__tbc_type, __tbc, 0x24);
DEFINE_SFR(__sfr_byte, __eea, 0x25);
DEFINE_SFR(__sfr_byte, __eed, 0x26);
DEFINE_SFR(__pc_type, __pc, 0x27);
DEFINE_SFR(__pcc_type, __pcc, 0x28);
DEFINE_SFR(__pcpu_type, __pcpu, 0x29);
DEFINE_SFR(__ctm0c0_type, __ctm0c0, 0x2a);
DEFINE_SFR(__ctm0c1_type, __ctm0c1, 0x2b);
DEFINE_SFR(__sfr_byte, __ctm0dl, 0x2c);
DEFINE_SFR(__sfr_byte, __ctm0dh, 0x2d);
DEFINE_SFR(__sfr_byte, __ctm0al, 0x2e);
DEFINE_SFR(__sfr_byte, __ctm0ah, 0x2f);
DEFINE_SFR(__ptm0c0_type, __ptm0c0, 0x30);
DEFINE_SFR(__ptm0c1_type, __ptm0c1, 0x31);
DEFINE_SFR(__sfr_byte, __ptm0dl, 0x32);
DEFINE_SFR(__sfr_byte, __ptm0dh, 0x33);
DEFINE_SFR(__sfr_byte, __ptm0al, 0x34);
DEFINE_SFR(__sfr_byte, __ptm0ah, 0x35);
DEFINE_SFR(__sfr_byte, __ptm0rpl, 0x36);
DEFINE_SFR(__sfr_byte, __ptm0rph, 0x37);
DEFINE_SFR(__iicc0_type, __iicc0, 0x38);
DEFINE_SFR(__iicc1_type, __iicc1, 0x39);
DEFINE_SFR(__sfr_byte, __iicd, 0x3a);
DEFINE_SFR(__iica_type, __iica, 0x3b);
DEFINE_SFR(__iictoc_type, __iictoc, 0x3c);
DEFINE_SFR(__sfr_byte, __sadol, 0x40);
DEFINE_SFR(__sfr_byte, __sadoh, 0x41);
DEFINE_SFR(__sadc0_type, __sadc0, 0x42);
DEFINE_SFR(__sadc1_type, __sadc1, 0x43);
DEFINE_SFR(__sadc2_type, __sadc2, 0x44);
DEFINE_SFR(__pb_type, __pb, 0x45);
DEFINE_SFR(__pbc_type, __pbc, 0x46);
DEFINE_SFR(__pbpu_type, __pbpu, 0x47);
DEFINE_SFR(__pbs0_type, __pbs0, 0x48);
DEFINE_SFR(__ppgc_type, __ppgc, 0x49);
DEFINE_SFR(__ppgpc_type, __ppgpc, 0x4a);
DEFINE_SFR(__ppgta_type, __ppgta, 0x4b);
DEFINE_SFR(__ppgtb_type, __ppgtb, 0x4c);
DEFINE_SFR(__ppgtex_type, __ppgtex, 0x4d);
DEFINE_SFR(__sfr_byte, __pwlt, 0x4e);
DEFINE_SFR(__tdc_type, __tdc, 0x4f);
DEFINE_SFR(__ctm1c0_type, __ctm1c0, 0x50);
DEFINE_SFR(__ctm1c1_type, __ctm1c1, 0x51);
DEFINE_SFR(__sfr_byte, __ctm1dl, 0x52);
DEFINE_SFR(__sfr_byte, __ctm1dh, 0x53);
DEFINE_SFR(__sfr_byte, __ctm1al, 0x54);
DEFINE_SFR(__sfr_byte, __ctm1ah, 0x55);
DEFINE_SFR(__u0sr_type, __u0sr, 0x58);
DEFINE_SFR(__u0cr1_type, __u0cr1, 0x59);
DEFINE_SFR(__u0cr2_type, __u0cr2, 0x5a);
DEFINE_SFR(__sfr_byte, __txr_rxr0, 0x5b);
DEFINE_SFR(__sfr_byte, __brg0, 0x5c);
DEFINE_SFR(__ppgctc_type, __ppgctc, 0x60);
DEFINE_SFR(__sfr_byte, __syncbuf, 0x61);
DEFINE_SFR(__pckc_type, __pckc, 0x62);
DEFINE_SFR(__ctrl_type, __ctrl, 0x63);
DEFINE_SFR(__pcs0_type, __pcs0, 0x64);
DEFINE_SFR(__pcs1_type, __pcs1, 0x65);
DEFINE_SFR(__cmp1c2_type, __cmp1c2, 0x66);
DEFINE_SFR(__cmp3c2_type, __cmp3c2, 0x67);
DEFINE_SFR(__cmp0c0_type, __cmp0c0, 0x68);
DEFINE_SFR(__cmp0c1_type, __cmp0c1, 0x69);
DEFINE_SFR(__cmp0c2_type, __cmp0c2, 0x6a);
DEFINE_SFR(__cmp0c3_type, __cmp0c3, 0x6b);
DEFINE_SFR(__hircc_type, __hircc, 0x6c);
DEFINE_SFR(__cmp1c0_type, __cmp1c0, 0x6d);
DEFINE_SFR(__cmp1c1_type, __cmp1c1, 0x6e);
DEFINE_SFR(__sfr_byte, __cmp1da, 0x6f);
DEFINE_SFR(__cmp2c0_type, __cmp2c0, 0x70);
DEFINE_SFR(__cmp2c1_type, __cmp2c1, 0x71);
DEFINE_SFR(__sfr_byte, __cmp2da, 0x72);
DEFINE_SFR(__cmp3c0_type, __cmp3c0, 0x73);
DEFINE_SFR(__cmp3c1_type, __cmp3c1, 0x74);
DEFINE_SFR(__sfr_byte, __cmp3da, 0x75);
DEFINE_SFR(__cmp4c0_type, __cmp4c0, 0x76);
DEFINE_SFR(__cmp4c1_type, __cmp4c1, 0x77);
DEFINE_SFR(__cmp4c2_type, __cmp4c2, 0x78);
DEFINE_SFR(__sfr_byte, __cmp4da, 0x79);
DEFINE_SFR(__opac0_type, __opac0, 0x7a);
DEFINE_SFR(__opac1_type, __opac1, 0x7b);
DEFINE_SFR(__pas0_type, __pas0, 0x7c);
DEFINE_SFR(__pas1_type, __pas1, 0x7d);
DEFINE_SFR(__sfr_byte, __tmr, 0x7e);
DEFINE_SFR(__tmrc_type, __tmrc, 0x7f);
DEFINE_SFR(__eec_type, __eec, 0x140);
DEFINE_SFR(__sfr_byte, __iar0, 0x00);
DEFINE_SFR(__sfr_byte, __iar1, 0x02);
DEFINE_SFR(__sfr_byte, __iar2, 0x0C);

#define _iar0     __iar0
#define _iar1     __iar1
#define _iar2     __iar2
#define _mp0      __mp0
#define _mp1l     __mp1l
#define _mp1h     __mp1h
#define _acc      __acc
#define _pcl      __pcl
#define _tblp     __tblp
#define _tblh     __tblh
#define _tbhp     __tbhp
#define _status   __status.byte
#define _mp2l     __mp2l
#define _mp2h     __mp2h
#define _scc      __scc.byte
#define _intc0    __intc0.byte
#define _intc1    __intc1.byte
#define _intc2    __intc2.byte
#define _intc3    __intc3.byte
#define _pa       __pa.byte
#define _pac      __pac.byte
#define _papu     __papu.byte
#define _pawu     __pawu.byte
#define _mfi0     __mfi0.byte
#define _mfi1     __mfi1.byte
#define _mfi2     __mfi2.byte
#define _mfi3     __mfi3.byte
#define _wdtc     __wdtc.byte
#define _rstfc    __rstfc.byte
#define _lvrc     __lvrc.byte
#define _lvdc     __lvdc.byte
#define _integ    __integ.byte
#define _tbc      __tbc.byte
#define _eea      __eea
#define _eed      __eed
#define _pc       __pc.byte
#define _pcc      __pcc.byte
#define _pcpu     __pcpu.byte
#define _ctm0c0   __ctm0c0.byte
#define _ctm0c1   __ctm0c1.byte
#define _ctm0dl   __ctm0dl
#define _ctm0dh   __ctm0dh
#define _ctm0al   __ctm0al
#define _ctm0ah   __ctm0ah
#define _ptm0c0   __ptm0c0.byte
#define _ptm0c1   __ptm0c1.byte
#define _ptm0dl   __ptm0dl
#define _ptm0dh   __ptm0dh
#define _ptm0al   __ptm0al
#define _ptm0ah   __ptm0ah
#define _ptm0rpl  __ptm0rpl
#define _ptm0rph  __ptm0rph
#define _iicc0    __iicc0.byte
#define _iicc1    __iicc1.byte
#define _iicd     __iicd
#define _iica     __iica.byte
#define _iictoc   __iictoc.byte
#define _sadol    __sadol
#define _sadoh    __sadoh
#define _sadc0    __sadc0.byte
#define _sadc1    __sadc1.byte
#define _sadc2    __sadc2.byte
#define _pb       __pb.byte
#define _pbc      __pbc.byte
#define _pbpu     __pbpu.byte
#define _pbs0     __pbs0.byte
#define _ppgc     __ppgc.byte
#define _ppgpc    __ppgpc.byte
#define _ppgta    __ppgta.byte
#define _ppgtb    __ppgtb.byte
#define _ppgtex   __ppgtex.byte
#define _pwlt     __pwlt
#define _tdc      __tdc.byte
#define _ctm1c0   __ctm1c0.byte
#define _ctm1c1   __ctm1c1.byte
#define _ctm1dl   __ctm1dl
#define _ctm1dh   __ctm1dh
#define _ctm1al   __ctm1al
#define _ctm1ah   __ctm1ah
#define _u0sr     __u0sr.byte
#define _u0cr1    __u0cr1.byte
#define _u0cr2    __u0cr2.byte
#define _txr_rxr0 __txr_rxr0
#define _brg0     __brg0
#define _ppgctc   __ppgctc.byte
#define _syncbuf  __syncbuf
#define _pckc     __pckc.byte
#define _ctrl     __ctrl.byte
#define _pcs0     __pcs0.byte
#define _pcs1     __pcs1.byte
#define _cmp1c2   __cmp1c2.byte
#define _cmp3c2   __cmp3c2.byte
#define _cmp0c0   __cmp0c0.byte
#define _cmp0c1   __cmp0c1.byte
#define _cmp0c2   __cmp0c2.byte
#define _cmp0c3   __cmp0c3.byte
#define _hircc    __hircc.byte
#define _cmp1c0   __cmp1c0.byte
#define _cmp1c1   __cmp1c1.byte
#define _cmp1da   __cmp1da
#define _cmp2c0   __cmp2c0.byte
#define _cmp2c1   __cmp2c1.byte
#define _cmp2da   __cmp2da
#define _cmp3c0   __cmp3c0.byte
#define _cmp3c1   __cmp3c1.byte
#define _cmp3da   __cmp3da
#define _cmp4c0   __cmp4c0.byte
#define _cmp4c1   __cmp4c1.byte
#define _cmp4c2   __cmp4c2.byte
#define _cmp4da   __cmp4da
#define _opac0    __opac0.byte
#define _opac1    __opac1.byte
#define _pas0     __pas0.byte
#define _pas1     __pas1.byte
#define _tmr      __tmr
#define _tmrc     __tmrc.byte
#define _eec      __eec.byte

#define _c        __status.bits.__c
#define _ac       __status.bits.__ac
#define _z        __status.bits.__z
#define _ov       __status.bits.__ov
#define _pdf      __status.bits.__pdf
#define _to       __status.bits.__to
#define _cz       __status.bits.__cz
#define _sc       __status.bits.__sc
#define _fsiden   __scc.bits.__fsiden
#define _fhiden   __scc.bits.__fhiden
#define _cks0     __scc.bits.__cks0
#define _cks1     __scc.bits.__cks1
#define _cks2     __scc.bits.__cks2
#define _emi      __intc0.bits.__emi
#define _int0e    __intc0.bits.__int0e
#define _cp0e     __intc0.bits.__cp0e
#define _cp1e     __intc0.bits.__cp1e
#define _int0f    __intc0.bits.__int0f
#define _cp0f     __intc0.bits.__cp0f
#define _cp1f     __intc0.bits.__cp1f
#define _cp2e     __intc1.bits.__cp2e
#define _cp3e     __intc1.bits.__cp3e
#define _cp4e     __intc1.bits.__cp4e
#define _synce    __intc1.bits.__synce
#define _cp2f     __intc1.bits.__cp2f
#define _cp3f     __intc1.bits.__cp3f
#define _cp4f     __intc1.bits.__cp4f
#define _syncf    __intc1.bits.__syncf
#define _iice     __intc2.bits.__iice
#define _mf0e     __intc2.bits.__mf0e
#define _tb1e     __intc2.bits.__tb1e
#define _te       __intc2.bits.__te
#define _iicf     __intc2.bits.__iicf
#define _mf0f     __intc2.bits.__mf0f
#define _tb1f     __intc2.bits.__tb1f
#define _tf       __intc2.bits.__tf
#define _ur0e     __intc3.bits.__ur0e
#define _mf1e     __intc3.bits.__mf1e
#define _mf2e     __intc3.bits.__mf2e
#define _mf3e     __intc3.bits.__mf3e
#define _ur0f     __intc3.bits.__ur0f
#define _mf1f     __intc3.bits.__mf1f
#define _mf2f     __intc3.bits.__mf2f
#define _mf3f     __intc3.bits.__mf3f
#define _pa0      __pa.bits.__pa0
#define _pa1      __pa.bits.__pa1
#define _pa2      __pa.bits.__pa2
#define _pa3      __pa.bits.__pa3
#define _pa4      __pa.bits.__pa4
#define _pa5      __pa.bits.__pa5
#define _pa6      __pa.bits.__pa6
#define _pa7      __pa.bits.__pa7
#define _pac0     __pac.bits.__pac0
#define _pac1     __pac.bits.__pac1
#define _pac2     __pac.bits.__pac2
#define _pac3     __pac.bits.__pac3
#define _pac4     __pac.bits.__pac4
#define _pac5     __pac.bits.__pac5
#define _pac6     __pac.bits.__pac6
#define _pac7     __pac.bits.__pac7
#define _papu0    __papu.bits.__papu0
#define _papu1    __papu.bits.__papu1
#define _papu2    __papu.bits.__papu2
#define _papu3    __papu.bits.__papu3
#define _papu4    __papu.bits.__papu4
#define _papu5    __papu.bits.__papu5
#define _papu6    __papu.bits.__papu6
#define _papu7    __papu.bits.__papu7
#define _pawu0    __pawu.bits.__pawu0
#define _pawu1    __pawu.bits.__pawu1
#define _pawu2    __pawu.bits.__pawu2
#define _pawu3    __pawu.bits.__pawu3
#define _pawu4    __pawu.bits.__pawu4
#define _pawu5    __pawu.bits.__pawu5
#define _pawu6    __pawu.bits.__pawu6
#define _pawu7    __pawu.bits.__pawu7
#define _ptm0pe   __mfi0.bits.__ptm0pe
#define _ptm0ae   __mfi0.bits.__ptm0ae
#define _tb0e     __mfi0.bits.__tb0e
#define _ptm0pf   __mfi0.bits.__ptm0pf
#define _ptm0af   __mfi0.bits.__ptm0af
#define _tb0f     __mfi0.bits.__tb0f
#define _ctm0pe   __mfi1.bits.__ctm0pe
#define _ctm0ae   __mfi1.bits.__ctm0ae
#define _ade      __mfi1.bits.__ade
#define _ctm0pf   __mfi1.bits.__ctm0pf
#define _ctm0af   __mfi1.bits.__ctm0af
#define _adf      __mfi1.bits.__adf
#define _ctm1pe   __mfi2.bits.__ctm1pe
#define _ctm1ae   __mfi2.bits.__ctm1ae
#define _dee      __mfi2.bits.__dee
#define _ctm1pf   __mfi2.bits.__ctm1pf
#define _ctm1af   __mfi2.bits.__ctm1af
#define _def      __mfi2.bits.__def
#define _int1e    __mfi3.bits.__int1e
#define _lve      __mfi3.bits.__lve
#define _int1f    __mfi3.bits.__int1f
#define _lvf      __mfi3.bits.__lvf
#define _ws0      __wdtc.bits.__ws0
#define _ws1      __wdtc.bits.__ws1
#define _ws2      __wdtc.bits.__ws2
#define _we0      __wdtc.bits.__we0
#define _we1      __wdtc.bits.__we1
#define _we2      __wdtc.bits.__we2
#define _we3      __wdtc.bits.__we3
#define _we4      __wdtc.bits.__we4
#define _wrf      __rstfc.bits.__wrf
#define _lrf      __rstfc.bits.__lrf
#define _lvrf     __rstfc.bits.__lvrf
#define _lvs0     __lvrc.bits.__lvs0
#define _lvs1     __lvrc.bits.__lvs1
#define _lvs2     __lvrc.bits.__lvs2
#define _lvs3     __lvrc.bits.__lvs3
#define _lvs4     __lvrc.bits.__lvs4
#define _lvs5     __lvrc.bits.__lvs5
#define _lvs6     __lvrc.bits.__lvs6
#define _lvs7     __lvrc.bits.__lvs7
#define _vlvd0    __lvdc.bits.__vlvd0
#define _vlvd1    __lvdc.bits.__vlvd1
#define _vlvd2    __lvdc.bits.__vlvd2
#define _vbgen    __lvdc.bits.__vbgen
#define _lvden    __lvdc.bits.__lvden
#define _lvdo     __lvdc.bits.__lvdo
#define _int0s0   __integ.bits.__int0s0
#define _int0s1   __integ.bits.__int0s1
#define _int1s0   __integ.bits.__int1s0
#define _int1s1   __integ.bits.__int1s1
#define _tb00     __tbc.bits.__tb00
#define _tb01     __tbc.bits.__tb01
#define _tb02     __tbc.bits.__tb02
#define _tb10     __tbc.bits.__tb10
#define _tb11     __tbc.bits.__tb11
#define _tbck     __tbc.bits.__tbck
#define _tbon     __tbc.bits.__tbon
#define _pc0      __pc.bits.__pc0
#define _pc1      __pc.bits.__pc1
#define _pc2      __pc.bits.__pc2
#define _pc3      __pc.bits.__pc3
#define _pc4      __pc.bits.__pc4
#define _pcc0     __pcc.bits.__pcc0
#define _pcc1     __pcc.bits.__pcc1
#define _pcc2     __pcc.bits.__pcc2
#define _pcc3     __pcc.bits.__pcc3
#define _pcc4     __pcc.bits.__pcc4
#define _pcpu0    __pcpu.bits.__pcpu0
#define _pcpu1    __pcpu.bits.__pcpu1
#define _pcpu2    __pcpu.bits.__pcpu2
#define _pcpu3    __pcpu.bits.__pcpu3
#define _pcpu4    __pcpu.bits.__pcpu4
#define _ct0rp0   __ctm0c0.bits.__ct0rp0
#define _ct0rp1   __ctm0c0.bits.__ct0rp1
#define _ct0rp2   __ctm0c0.bits.__ct0rp2
#define _ct0on    __ctm0c0.bits.__ct0on
#define _ct0ck0   __ctm0c0.bits.__ct0ck0
#define _ct0ck1   __ctm0c0.bits.__ct0ck1
#define _ct0ck2   __ctm0c0.bits.__ct0ck2
#define _ct0pau   __ctm0c0.bits.__ct0pau
#define _ct0cclr  __ctm0c1.bits.__ct0cclr
#define _ct0dpx   __ctm0c1.bits.__ct0dpx
#define _ct0pol   __ctm0c1.bits.__ct0pol
#define _ct0oc    __ctm0c1.bits.__ct0oc
#define _ct0io0   __ctm0c1.bits.__ct0io0
#define _ct0io1   __ctm0c1.bits.__ct0io1
#define _ct0m0    __ctm0c1.bits.__ct0m0
#define _ct0m1    __ctm0c1.bits.__ct0m1
#define _pt0on    __ptm0c0.bits.__pt0on
#define _pt0ck0   __ptm0c0.bits.__pt0ck0
#define _pt0ck1   __ptm0c0.bits.__pt0ck1
#define _pt0ck2   __ptm0c0.bits.__pt0ck2
#define _pt0pau   __ptm0c0.bits.__pt0pau
#define _pt0cclr  __ptm0c1.bits.__pt0cclr
#define _pt0capts __ptm0c1.bits.__pt0capts
#define _pt0pol   __ptm0c1.bits.__pt0pol
#define _pt0oc    __ptm0c1.bits.__pt0oc
#define _pt0io0   __ptm0c1.bits.__pt0io0
#define _pt0io1   __ptm0c1.bits.__pt0io1
#define _pt0m0    __ptm0c1.bits.__pt0m0
#define _pt0m1    __ptm0c1.bits.__pt0m1
#define _iicen    __iicc0.bits.__iicen
#define _iicdeb0  __iicc0.bits.__iicdeb0
#define _iicdeb1  __iicc0.bits.__iicdeb1
#define _rxak     __iicc1.bits.__rxak
#define _iamwu    __iicc1.bits.__iamwu
#define _srw      __iicc1.bits.__srw
#define _txak     __iicc1.bits.__txak
#define _htx      __iicc1.bits.__htx
#define _hbb      __iicc1.bits.__hbb
#define _haas     __iicc1.bits.__haas
#define _hcf      __iicc1.bits.__hcf
#define _a0       __iica.bits.__a0
#define _a1       __iica.bits.__a1
#define _a2       __iica.bits.__a2
#define _a3       __iica.bits.__a3
#define _a4       __iica.bits.__a4
#define _a5       __iica.bits.__a5
#define _a6       __iica.bits.__a6
#define _iictos0  __iictoc.bits.__iictos0
#define _iictos1  __iictoc.bits.__iictos1
#define _iictos2  __iictoc.bits.__iictos2
#define _iictos3  __iictoc.bits.__iictos3
#define _iictos4  __iictoc.bits.__iictos4
#define _iictos5  __iictoc.bits.__iictos5
#define _iictof   __iictoc.bits.__iictof
#define _iictoen  __iictoc.bits.__iictoen
#define _sacs0    __sadc0.bits.__sacs0
#define _sacs1    __sadc0.bits.__sacs1
#define _sacs2    __sadc0.bits.__sacs2
#define _sacs3    __sadc0.bits.__sacs3
#define _adrfs    __sadc0.bits.__adrfs
#define _adcen    __sadc0.bits.__adcen
#define _adbz     __sadc0.bits.__adbz
#define _start    __sadc0.bits.__start
#define _sacks0   __sadc1.bits.__sacks0
#define _sacks1   __sadc1.bits.__sacks1
#define _sacks2   __sadc1.bits.__sacks2
#define _sains0   __sadc1.bits.__sains0
#define _sains1   __sadc1.bits.__sains1
#define _sains2   __sadc1.bits.__sains2
#define _sains3   __sadc1.bits.__sains3
#define _pgags0   __sadc2.bits.__pgags0
#define _pgags1   __sadc2.bits.__pgags1
#define _savrs0   __sadc2.bits.__savrs0
#define _savrs1   __sadc2.bits.__savrs1
#define _pgais    __sadc2.bits.__pgais
#define _verify0  __sadc2.bits.__verify0
#define _adpgaen  __sadc2.bits.__adpgaen
#define _pb0      __pb.bits.__pb0
#define _pb1      __pb.bits.__pb1
#define _pb2      __pb.bits.__pb2
#define _pb3      __pb.bits.__pb3
#define _pbc0     __pbc.bits.__pbc0
#define _pbc1     __pbc.bits.__pbc1
#define _pbc2     __pbc.bits.__pbc2
#define _pbc3     __pbc.bits.__pbc3
#define _pbpu0    __pbpu.bits.__pbpu0
#define _pbpu1    __pbpu.bits.__pbpu1
#define _pbpu2    __pbpu.bits.__pbpu2
#define _pbpu3    __pbpu.bits.__pbpu3
#define _pbs00    __pbs0.bits.__pbs00
#define _pbs01    __pbs0.bits.__pbs01
#define _pbs02    __pbs0.bits.__pbs02
#define _pbs03    __pbs0.bits.__pbs03
#define _pcsd     __ppgc.bits.__pcsd
#define _trgmod   __ppgc.bits.__trgmod
#define _ptsyn    __ppgc.bits.__ptsyn
#define _rlbf     __ppgc.bits.__rlbf
#define _prsen    __ppgc.bits.__prsen
#define _pst      __ppgc.bits.__pst
#define _ppgpc0   __ppgpc.bits.__ppgpc0
#define _ppgpc1   __ppgpc.bits.__ppgpc1
#define _ppgpc2   __ppgpc.bits.__ppgpc2
#define _ppgpc3   __ppgpc.bits.__ppgpc3
#define _ppgpc4   __ppgpc.bits.__ppgpc4
#define _ppgpc5   __ppgpc.bits.__ppgpc5
#define _ppgpc6   __ppgpc.bits.__ppgpc6
#define _ppgpc7   __ppgpc.bits.__ppgpc7
#define _ppgta0   __ppgta.bits.__ppgta0
#define _ppgta1   __ppgta.bits.__ppgta1
#define _ppgta2   __ppgta.bits.__ppgta2
#define _ppgta3   __ppgta.bits.__ppgta3
#define _ppgta4   __ppgta.bits.__ppgta4
#define _ppgta5   __ppgta.bits.__ppgta5
#define _ppgta6   __ppgta.bits.__ppgta6
#define _ppgta7   __ppgta.bits.__ppgta7
#define _ppgtb0   __ppgtb.bits.__ppgtb0
#define _ppgtb1   __ppgtb.bits.__ppgtb1
#define _ppgtb2   __ppgtb.bits.__ppgtb2
#define _ppgtb3   __ppgtb.bits.__ppgtb3
#define _ppgtb4   __ppgtb.bits.__ppgtb4
#define _ppgtb5   __ppgtb.bits.__ppgtb5
#define _ppgtb6   __ppgtb.bits.__ppgtb6
#define _ppgtb7   __ppgtb.bits.__ppgtb7
#define _ppgta8   __ppgtex.bits.__ppgta8
#define _ppgtb8   __ppgtex.bits.__ppgtb8
#define _tdps0    __tdc.bits.__tdps0
#define _tdps1    __tdc.bits.__tdps1
#define _tdugs0   __tdc.bits.__tdugs0
#define _tdugs1   __tdc.bits.__tdugs1
#define _tdccs0   __tdc.bits.__tdccs0
#define _tdccs1   __tdc.bits.__tdccs1
#define _tdcce    __tdc.bits.__tdcce
#define _tduge    __tdc.bits.__tduge
#define _ct1rp0   __ctm1c0.bits.__ct1rp0
#define _ct1rp1   __ctm1c0.bits.__ct1rp1
#define _ct1rp2   __ctm1c0.bits.__ct1rp2
#define _ct1on    __ctm1c0.bits.__ct1on
#define _ct1ck0   __ctm1c0.bits.__ct1ck0
#define _ct1ck1   __ctm1c0.bits.__ct1ck1
#define _ct1ck2   __ctm1c0.bits.__ct1ck2
#define _ct1pau   __ctm1c0.bits.__ct1pau
#define _ct1cclr  __ctm1c1.bits.__ct1cclr
#define _ct1dpx   __ctm1c1.bits.__ct1dpx
#define _ct1pol   __ctm1c1.bits.__ct1pol
#define _ct1oc    __ctm1c1.bits.__ct1oc
#define _ct1io0   __ctm1c1.bits.__ct1io0
#define _ct1io1   __ctm1c1.bits.__ct1io1
#define _ct1m0    __ctm1c1.bits.__ct1m0
#define _ct1m1    __ctm1c1.bits.__ct1m1
#define _txif0    __u0sr.bits.__txif0
#define _tidle0   __u0sr.bits.__tidle0
#define _rxif0    __u0sr.bits.__rxif0
#define _ridle0   __u0sr.bits.__ridle0
#define _oerr0    __u0sr.bits.__oerr0
#define _ferr0    __u0sr.bits.__ferr0
#define _nf0      __u0sr.bits.__nf0
#define _perr0    __u0sr.bits.__perr0
#define _tx80     __u0cr1.bits.__tx80
#define _rx80     __u0cr1.bits.__rx80
#define _txbrk0   __u0cr1.bits.__txbrk0
#define _stops0   __u0cr1.bits.__stops0
#define _prt0     __u0cr1.bits.__prt0
#define _pren0    __u0cr1.bits.__pren0
#define _bno0     __u0cr1.bits.__bno0
#define _uarten0  __u0cr1.bits.__uarten0
#define _teie0    __u0cr2.bits.__teie0
#define _tiie0    __u0cr2.bits.__tiie0
#define _rie0     __u0cr2.bits.__rie0
#define _wake0    __u0cr2.bits.__wake0
#define _adden0   __u0cr2.bits.__adden0
#define _brgh0    __u0cr2.bits.__brgh0
#define _rxen0    __u0cr2.bits.__rxen0
#define _txen0    __u0cr2.bits.__txen0
#define _cts0     __ppgctc.bits.__cts0
#define _cts1     __ppgctc.bits.__cts1
#define _cton     __ppgctc.bits.__cton
#define _ovf      __ppgctc.bits.__ovf
#define _pckpsc0  __pckc.bits.__pckpsc0
#define _pckpsc1  __pckc.bits.__pckpsc1
#define _pckpsc2  __pckc.bits.__pckpsc2
#define _pckpsc3  __pckc.bits.__pckpsc3
#define _pcken    __pckc.bits.__pcken
#define _pckpol   __pckc.bits.__pckpol
#define _pckd     __pckc.bits.__pckd
#define _sdapc    __ctrl.bits.__sdapc
#define _sclpc    __ctrl.bits.__sclpc
#define _rxpc     __ctrl.bits.__rxpc
#define _tdccs2   __ctrl.bits.__tdccs2
#define _pcs00    __pcs0.bits.__pcs00
#define _pcs01    __pcs0.bits.__pcs01
#define _pcs02    __pcs0.bits.__pcs02
#define _pcs03    __pcs0.bits.__pcs03
#define _pcs04    __pcs0.bits.__pcs04
#define _pcs05    __pcs0.bits.__pcs05
#define _pcs06    __pcs0.bits.__pcs06
#define _pcs07    __pcs0.bits.__pcs07
#define _pcs10    __pcs1.bits.__pcs10
#define _pcs11    __pcs1.bits.__pcs11
#define _c1eg0    __cmp1c2.bits.__c1eg0
#define _c1eg1    __cmp1c2.bits.__c1eg1
#define _c3eg0    __cmp3c2.bits.__c3eg0
#define _c3eg1    __cmp3c2.bits.__c3eg1
#define _c0csw    __cmp0c0.bits.__c0csw
#define _c0rsw    __cmp0c0.bits.__c0rsw
#define _c0o      __cmp0c0.bits.__c0o
#define _c0chy    __cmp0c0.bits.__c0chy
#define _c0en     __cmp0c0.bits.__c0en
#define _c0eg0    __cmp0c0.bits.__c0eg0
#define _c0eg1    __cmp0c0.bits.__c0eg1
#define _c0of0    __cmp0c1.bits.__c0of0
#define _c0of1    __cmp0c1.bits.__c0of1
#define _c0of2    __cmp0c1.bits.__c0of2
#define _c0of3    __cmp0c1.bits.__c0of3
#define _c0of4    __cmp0c1.bits.__c0of4
#define _c0rs     __cmp0c1.bits.__c0rs
#define _c0ofm    __cmp0c1.bits.__c0ofm
#define _c0cx     __cmp0c1.bits.__c0cx
#define _c0db0    __cmp0c2.bits.__c0db0
#define _c0db1    __cmp0c2.bits.__c0db1
#define _c0db2    __cmp0c2.bits.__c0db2
#define _c0db3    __cmp0c2.bits.__c0db3
#define _c0db4    __cmp0c2.bits.__c0db4
#define _c0db5    __cmp0c2.bits.__c0db5
#define _ppgdl0   __cmp0c3.bits.__ppgdl0
#define _ppgdl1   __cmp0c3.bits.__ppgdl1
#define _ppgdl2   __cmp0c3.bits.__ppgdl2
#define _ppgdl3   __cmp0c3.bits.__ppgdl3
#define _ppgdl4   __cmp0c3.bits.__ppgdl4
#define _ppgdl5   __cmp0c3.bits.__ppgdl5
#define _hircen   __hircc.bits.__hircen
#define _hircf    __hircc.bits.__hircf
#define _c1db0    __cmp1c0.bits.__c1db0
#define _c1db1    __cmp1c0.bits.__c1db1
#define _c1rv     __cmp1c0.bits.__c1rv
#define _c1o      __cmp1c0.bits.__c1o
#define _c1chy    __cmp1c0.bits.__c1chy
#define _c1en     __cmp1c0.bits.__c1en
#define _c1rlen   __cmp1c0.bits.__c1rlen
#define _pspc1e   __cmp1c0.bits.__pspc1e
#define _c1of0    __cmp1c1.bits.__c1of0
#define _c1of1    __cmp1c1.bits.__c1of1
#define _c1of2    __cmp1c1.bits.__c1of2
#define _c1of3    __cmp1c1.bits.__c1of3
#define _c1of4    __cmp1c1.bits.__c1of4
#define _c1rs     __cmp1c1.bits.__c1rs
#define _c1ofm    __cmp1c1.bits.__c1ofm
#define _c1cx     __cmp1c1.bits.__c1cx
#define _c2db0    __cmp2c0.bits.__c2db0
#define _c2db1    __cmp2c0.bits.__c2db1
#define _c2rv     __cmp2c0.bits.__c2rv
#define _c2o      __cmp2c0.bits.__c2o
#define _c2chy    __cmp2c0.bits.__c2chy
#define _c2en     __cmp2c0.bits.__c2en
#define _c2eg0    __cmp2c0.bits.__c2eg0
#define _c2eg1    __cmp2c0.bits.__c2eg1
#define _c2of0    __cmp2c1.bits.__c2of0
#define _c2of1    __cmp2c1.bits.__c2of1
#define _c2of2    __cmp2c1.bits.__c2of2
#define _c2of3    __cmp2c1.bits.__c2of3
#define _c2of4    __cmp2c1.bits.__c2of4
#define _c2rs     __cmp2c1.bits.__c2rs
#define _c2ofm    __cmp2c1.bits.__c2ofm
#define _c2cx     __cmp2c1.bits.__c2cx
#define _c3db0    __cmp3c0.bits.__c3db0
#define _c3db1    __cmp3c0.bits.__c3db1
#define _c3rv     __cmp3c0.bits.__c3rv
#define _c3o      __cmp3c0.bits.__c3o
#define _c3chy    __cmp3c0.bits.__c3chy
#define _c3en     __cmp3c0.bits.__c3en
#define _pspc3e   __cmp3c0.bits.__pspc3e
#define _c3of0    __cmp3c1.bits.__c3of0
#define _c3of1    __cmp3c1.bits.__c3of1
#define _c3of2    __cmp3c1.bits.__c3of2
#define _c3of3    __cmp3c1.bits.__c3of3
#define _c3of4    __cmp3c1.bits.__c3of4
#define _c3rs     __cmp3c1.bits.__c3rs
#define _c3ofm    __cmp3c1.bits.__c3ofm
#define _c3cx     __cmp3c1.bits.__c3cx
#define _c4db0    __cmp4c0.bits.__c4db0
#define _c4db1    __cmp4c0.bits.__c4db1
#define _c4rv     __cmp4c0.bits.__c4rv
#define _c4o      __cmp4c0.bits.__c4o
#define _c4chy    __cmp4c0.bits.__c4chy
#define _c4en     __cmp4c0.bits.__c4en
#define _c4rlen   __cmp4c0.bits.__c4rlen
#define _pspc4e   __cmp4c0.bits.__pspc4e
#define _c4of0    __cmp4c1.bits.__c4of0
#define _c4of1    __cmp4c1.bits.__c4of1
#define _c4of2    __cmp4c1.bits.__c4of2
#define _c4of3    __cmp4c1.bits.__c4of3
#define _c4of4    __cmp4c1.bits.__c4of4
#define _c4rs     __cmp4c1.bits.__c4rs
#define _c4ofm    __cmp4c1.bits.__c4ofm
#define _c4cx     __cmp4c1.bits.__c4cx
#define _c4pc0    __cmp4c2.bits.__c4pc0
#define _c4pc1    __cmp4c2.bits.__c4pc1
#define _c4eg0    __cmp4c2.bits.__c4eg0
#define _c4eg1    __cmp4c2.bits.__c4eg1
#define _opax     __opac0.bits.__opax
#define _swr1     __opac0.bits.__swr1
#define _swr2     __opac0.bits.__swr2
#define _opag0    __opac0.bits.__opag0
#define _opag1    __opac0.bits.__opag1
#define _opag2    __opac0.bits.__opag2
#define _opam0    __opac0.bits.__opam0
#define _opam1    __opac0.bits.__opam1
#define _aof0     __opac1.bits.__aof0
#define _aof1     __opac1.bits.__aof1
#define _aof2     __opac1.bits.__aof2
#define _aof3     __opac1.bits.__aof3
#define _aof4     __opac1.bits.__aof4
#define _aof5     __opac1.bits.__aof5
#define _ars      __opac1.bits.__ars
#define _aofm     __opac1.bits.__aofm
#define _pas00    __pas0.bits.__pas00
#define _pas01    __pas0.bits.__pas01
#define _pas02    __pas0.bits.__pas02
#define _pas03    __pas0.bits.__pas03
#define _pas04    __pas0.bits.__pas04
#define _pas05    __pas0.bits.__pas05
#define _pas06    __pas0.bits.__pas06
#define _pas07    __pas0.bits.__pas07
#define _pas10    __pas1.bits.__pas10
#define _pas11    __pas1.bits.__pas11
#define _pas12    __pas1.bits.__pas12
#define _pas13    __pas1.bits.__pas13
#define _pas14    __pas1.bits.__pas14
#define _pas15    __pas1.bits.__pas15
#define _pas16    __pas1.bits.__pas16
#define _pas17    __pas1.bits.__pas17
#define _tpsc0    __tmrc.bits.__tpsc0
#define _tpsc1    __tmrc.bits.__tpsc1
#define _tpsc2    __tmrc.bits.__tpsc2
#define _ton      __tmrc.bits.__ton
#define _tm0      __tmrc.bits.__tm0
#define _tm1      __tmrc.bits.__tm1
#define _rd       __eec.bits.__rd
#define _rden     __eec.bits.__rden
#define _wr       __eec.bits.__wr
#define _wren     __eec.bits.__wren

#define ___mkstr(x)                #x
#define __EEPROM_DATA(a, b, c, d, e, f, g, h) \
                         asm("eeprom_data .section 'eeprom'"); \
                         asm("db\t" ___mkstr(a));        \
                         asm("db\t" ___mkstr(b));        \
                         asm("db\t" ___mkstr(c));        \
                         asm("db\t" ___mkstr(d));        \
                         asm("db\t" ___mkstr(e));        \
                         asm("db\t" ___mkstr(f));        \
                         asm("db\t" ___mkstr(g));        \
                         asm("db\t" ___mkstr(h));        

#endif // _NW2018_H_
