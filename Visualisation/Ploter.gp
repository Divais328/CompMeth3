set terminal jpeg font "Arials,16"
set output "Errors.jpeg"
set xlabel "T"
set ylabel "Error"
set title "Max errors"
plot [0.1:1][0.05:0.2]"Error_10_5_5.txt" w l lw 2 t "P = 10, N = M = 5", "Error_40_10_10.txt" w l lw 2 t "P = 40; N = M = 10", "Error_160_20_20.txt" w l lw 2 t "P = 160; N = M = 20"



set terminal gif animate delay 48 font "Arials,16"
set output "Solution_10_5_5.gif"
set title "Solution of heat condactivity equation.\nP = 10, N = M = 5" 
set xlabel "X"
set ylabel "Y"
set zlabel "T"
set pm3d
set key at graph 0.3, 2.4
set zrange [0:1]
set cbrange [0:1]
set hidden3d 
# set grid
# set key right top


do for [i=3:13] {
    splot "Solution_10_5_5.txt" u 1:2:i w l t sprintf("T = %1.2f",(i-3)/10.)
}

set terminal gif animate delay 12 font "Arials,16"
set output "Solution_40_10_10.gif"
set title "Solution of heat condactivity equation.\nP = 40; N = M = 10" 
do for [i=3:43] {
    splot "Solution_40_10_10.txt" u 1:2:i w l t sprintf("T = %1.2f",(i-3)/40.)
}

set terminal gif animate delay 3 font "Arials,16"
set output "Solution_160_20_20.gif"
set title "Solution of heat condactivity equation.\nP = 160; N = M = 20" 
do for [i=3:163] {
    splot "Solution_160_20_20.txt" u 1:2:i w l t sprintf("T = %1.2f",(i-3)/160.)
}

