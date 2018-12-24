.protect
.lib '~/TD-LO18-SP-2003v4R/l018ll_io50_v1p3.lib'  TT
.unprotect
*************************************************
.subckt reg1 D Q clk clk1 vdd gnd
****  Circuit ****************

*****Trans tube1
M1 D clk  Ain vdd p18ll W=0.18u L=0.18u
M2 D clk1 Ain gnd n18ll W=0.18u L=0.18u

******inv1
M3 Aout Ain vdd vdd p18ll w=0.70u l=0.18u
M4 Aout Ain gnd gnd n18ll w=0.30u l=0.18u

*****Trans tube2
M5 Aout clk1 B vdd p18ll W=0.18u L=0.18u
M6 Aout clk  B gnd n18ll W=0.18u L=0.18u

******inv2
M7 Q B vdd vdd p18ll w=0.80u l=0.18u
M8 Q B gnd gnd n18ll w=0.31u l=0.18u

C1 Ain gnd 0.6f
C2 B gnd 0.6f
.ends
*************************************************
.subckt  reg2 d q clk clk1  vdd gnd
M1 nclk clk gnd gnd n18ll L=0.18u W=0.81u
M2 nclk clk vdd vdd p18ll L=.18u W=0.81u

M3 d nclk a gnd n18ll L=0.18u W=0.18u
M4 a clk d vdd p18ll L=0.18u W=0.54u

M5 c a gnd gnd n18ll L=0.18u W=0.24u
M6 c a vdd vdd p18ll L=0.18u W=0.72u

M7 c clk b gnd n18ll L=0.18u W=0.63u
M8 b nclk c vdd p18ll L=0.18u W=0.63u

M9 q b gnd gnd n18ll L=0.18u W=0.54u
M10 q b vdd vdd p18ll L=0.18u W=1.62u

C1 h gnd 0.1f
C2 j gnd 0.1f
.ends reg2


******add1=A+B
.subckt add1 a0 b0 f0 b0B vdd gnd
M1 f0 a0 b0 vdd p18ll w=0.18u l=0.18u
M2 f0 a0 b0B gnd n18ll w=0.18u l=0.18u
M3 f0 b0 a0 vdd p18ll w=0.18u l=0.18u
M4 f0 b0b a0 gnd n18ll w=0.18u l=0.18u
.ends add1
*************************************************
******Manchester pipe
.subckt Manchester cin cout D p pB gb vdd gnd
M1 cin pB cout vdd p18ll w=0.9u l=0.18u
M2 cin p cout gnd n18ll w=0.18u l=0.18u
M3 cout gb vdd vdd p18ll w=0.9u l=0.18u
M4 cout D gnd gnd n18ll w=0.18u l=0.18u
.ends Manchester
*************************************************
******Gi*nand*Di
.subckt Gi a0 b0 g0b vdd gnd
M1 g0b A0 vdd vdd p18ll w=9.26u l=0.18u
M2 g0b B0 vdd vdd p18ll w=5.26u l=0.18u
M3 g0b A0 lnk gnd n18ll w=22.26u l=0.18u
M4 lnk B0 gnd gnd n18ll w=20.26u l=0.18u
.ends Gi
*************************************************
******inv
.subckt inv in out vdd gnd
M1 out in vdd vdd p18ll w=1.8u l=0.18u
M2 out in gnd gnd n18ll w=2.5u l=0.18u
.ends inv
**********************************************************************
.subckt  reg clk clkb vdd gnd D Q

******cs
M1 n4 clk n1 vdd p18ll w=0.9u l=0.18u
M2 n4 clkb n1 gnd n18ll w=0.5u l=0.18u
******cs
M3 n2 clkb n1 vdd p18ll w=0.9u l=0.18u
M4 n2 clk n1 gnd n18ll w=0.5u l=0.18u
******cs
M5 n6 clkb n7 vdd p18ll w=2u l=0.18u
M6 n6 clk n7 gnd n18ll w=0.5u l=0.18u
******cs        
M7 n8 clk n7 vdd p18ll w=0.9u l=0.18u
M8 n8 clkb n7 gnd n18ll w=0.5u l=0.18u

******inv
M9 n4 D vdd vdd p18ll w=0.9u l=0.18u
M10 n4 D gnd gnd n18ll w=0.9u l=0.18u
******inv
M11 n2 n3 vdd vdd p18ll w=0.9u l=0.18u
M12 n2 n3 gnd gnd n18ll w=2.2u l=0.18u

******inv
M13 n3 n1 vdd vdd p18ll w=0.9u l=0.18u
M14 n3 n1 gnd gnd n18ll w=2.5u l=0.18u

******inv
M15 n8 Q vdd vdd p18ll w=0.9u l=0.18u
M16 n8 Q gnd gnd n18ll w=0.5u l=0.18u

******inv
M17 n6 n3 vdd vdd p18ll w=1.8u l=0.18u
M18 n6 n3 gnd gnd n18ll w=2.5u l=0.18u

*******CLKB
M19 clkb clk vdd vdd p18ll w=0.9u l=0.18u
M20 clkb clk gnd gnd n18ll w=2.6u l=0.18u
********inv near Q
M21 Q n7 vdd vdd p18ll w=2.0u l=0.18u
M22 Q n7 gnd gnd n18ll w=2.5u l=0.18u
.ends

*******low
*A+B
X1 a0 b0 p0 b0B vdd gnd add1
*A+B+CIN0
X2 p0 cin0 s0 cin0B vdd gnd add1
*COUT0
X3 a0 b0 g0b vdd gnd Gi
X4 g0b g0 vdd gnd inv
*~A ~B ~CIN0
X5 cin0 cin0b vdd gnd inv
X6 b0 b0B vdd gnd inv
******high
*cin1
X7  g0 cout D1 p1 p1b g1B vdd gnd Manchester
*D1
X8 a1B b1B D1B vdd gnd Gi
X9 D1B D1 vdd gnd inv
X10 a1 a1B vdd gnd inv
X11 b1 b1B vdd gnd inv
*G1!
X12 a1 b1 g1B vdd gnd Gi
X15 g1B g1 vdd gnd inv
*add1 add2 P1B P1
X13 a1 b1 p1 b1B vdd gnd add1
X14 p1 g0 s1 g0B vdd gnd add1
X16 clk clkb vdd gnd inv
******************************************************************
*****reg1
X26 a0_r a0 clk clkb vdd gnd reg1
*****reg2
X27 b0_r b0 clk clkb vdd gnd reg1
*****reg3
X28 a1_r a1 clk clkb vdd gnd reg1
***
*****reg4
X29 b1_r b1 clk clkb vdd gnd reg1
***
*****reg5
X30 clk clkb vdd gnd s0 s0_r  reg
***
*****reg6
X31 clk clkb vdd gnd s1 s1_r reg
***
*****reg7
X32 clk clkb vdd gnd cout cout_r reg
***
.ic b1 0v
.ic a1 0v
.ic b0 0v
.ic a0 0v
.ic s0_r 0v
.ic s1_r 0v
.ic cout_r 0v

***dc
v1 vdd gnd dc 1.8v
v2 gnd gnd dc 0v
v7 cin0 gnd dc 0v
*v8 z gnd dc 0v
v3 a1_r gnd PWL 330ns 0v, 331ns 1.8v
v4 a0_r gnd PWL 170ns 0v, 171ns 1.8v, 330ns 1.8v, 331ns 0v, 490ns 0v, 491ns 1.8v
v5 b1_r gnd PWL 90ns 0v, 91ns 1.8v, 170ns 1.8v, 171ns 0v, 250ns 0v, 251ns 1.8v,
+330ns 1.8v, 331ns 0v, 410ns 0v, 411ns 1.8v, 490ns 1.8v, 491ns 0v, 570ns 0v,
+571ns 1.8v
v6 b0_r gnd PWL 50ns 0v, 51ns 1.8v, 90ns 1.8v, 91ns 0v, 130ns 0v, 131ns 1.8v,
+170ns 1.8v, 171ns 0v, 210ns 0v, 211ns 1.8v, 250ns 1.8v, 251ns 0v, 290ns 0v,
+291ns 1.8v,330ns 1.8v, 331ns 0v, 370ns 0v, 371ns 1.8v, 410ns 1.8v, 411ns 0v,
+450ns 0v, 451ns 1.8v, 490ns 1.8v, 491ns 0v, 530ns 0v, 531ns 1.8v, 570ns 1.8v,
+571ns 0v, 610ns 0v, 611ns 1.8v

vincLk cLk 0 PWL 20ns 0v, 21ns 1.8v,40ns 1.8v,41ns 0v,60ns 0v,61ns 1.8v,80ns 1.8v,
+81ns 0v, 100ns 0v,101ns 1.8v, 120ns 1.8v,121ns 0v, 140ns 0v,141ns 1.8v, 160ns
+1.8v,161ns 0v,180ns 0v,181ns 1.8v, 200ns 1.8v,201ns 0v, 220ns 0v,221ns 1.8v,
+240ns 1.8v,241ns 0v, 260ns 0v,261ns 1.8v,280ns 1.8v, 281ns 0v,300ns 0v, 301ns
+1.8v,320ns 1.8v, 321ns 0v,340ns 0v, 341ns 1.8v,360ns 1.8v,361ns 0v, 380ns 0v,
+381ns 1.8v, 400ns 1.8v,401ns 0v, 420ns 0v,421ns 1.8v, 440ns 1.8v, 441ns 0v,
+460ns 0v, 461ns 1.8v,480ns 1.8v, 481ns 0v,500ns 0v, 501ns 1.8v,520ns 1.8v,
+521ns 0v,540ns 0v,541ns 1.8v, 560ns 1.8v,561ns 0v, 580ns 0v,581ns 1.8v, 600ns
+1.8v,601ns 0v, 620ns 0v,621ns 1.8v,640ns 1.8v, 641ns 0v

*.dc Vin 0v 1.8v 0.1v
.tran 1ns 800ns
*.print v(CLK) v(Q) v(D)
.print v(clk) v (cout_r)  v(a0) v(a1) v(b0) v(b1) v(s0_r) v(s1_r)  v(cout) v((g0) v(g0B) v(Di1) v(Di1B) v(Di0b) v(Di0) v(p1) v(p10)
.end

                                                                       
