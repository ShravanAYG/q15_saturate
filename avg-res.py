def avg_from_file(fname):
    with open(fname) as f:
        vals = [float(line.strip()) for line in f if line.strip()]
    return sum(vals) / len(vals)

ref_avg = avg_from_file("res-ref.txt")
rvv_avg = avg_from_file("res-rvv.txt")

print(f"Average scalar cycles : {ref_avg:.2f}")
print(f"Average RVV cycles : {rvv_avg:.2f}")
print(f"Speedup : {ref_avg / rvv_avg:.2f}x")

