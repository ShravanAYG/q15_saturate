#include <stdint.h>
#include <riscv_vector.h>

/*
 * Q15 saturating AXPY
 * y[i] = sat_q15(a[i] + alpha * b[i])
 */
void q15_axpy_rvv(const int16_t *a,
		  const int16_t *b, int16_t *y, int n, int16_t alpha)
{
	int i = 0;

	while (i < n) {
		size_t vl = vsetvl_e16m1(n - i);
		vint16m1_t va = vle16_v_i16m1(&a[i], vl);
		vint16m1_t vb = vle16_v_i16m1(&b[i], vl);
		vint32m2_t vb_w = vwcvtx_v_i32m2(vb, vl);
		vint32m2_t prod = vmul_vx_i32m2(vb_w, (int32_t) alpha, vl);
		vint32m2_t prod_q15 = vsra_vx_i32m2(prod, 15, vl);
		vint32m2_t va_w = vwcvtx_v_i32m2(va, vl);
		vint32m2_t acc = vadd_vv_i32m2(va_w, prod_q15, vl);
		vint16m1_t result = vnclip_wx_i16m1(acc, 0, vl);
		vse16_v_i16m1(&y[i], result, vl);
		i += vl;
	}
}
