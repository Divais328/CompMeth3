# set terminal jpeg font "Arials,16"
# set output "Errors.jpeg"
# set xlabel "T"
# set ylabel "Error"
# set title "Max errors"
# plot [0.1:1][0:0.1]"Error_10_5_5.txt" w l lw 2 t "P = 10, N = M = 5", "Error_40_10_10.txt" w l lw 2 t "P = 40; N = M = 10", "Error_160_20_20.txt" w l lw 2 t "P = 160; N = M = 20", "Error_640_40_40.txt" w l lw 2 t "P = 640; N = M = 40", "Error_2560_80_80.txt" w l lw 2 t "P = 2560; N = M = 80" 



set terminal gif animate delay 64 font "Arials,16"
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

set terminal gif animate delay 16 font "Arials,16"
set output "Solution_40_10_10.gif"
set title "Solution of heat condactivity equation.\nP = 40; N = M = 10" 
do for [i=3:43] {
    splot "Solution_40_10_10.txt" u 1:2:i w l t sprintf("T = %1.2f",(i-3)/40.)
}

set terminal gif animate delay 4 font "Arials,16"
set output "Solution_160_20_20.gif"
set title "Solution of heat condactivity equation.\nP = 160; N = M = 20" 
do for [i=3:163] {
    splot "Solution_160_20_20.txt" u 1:2:i w l t sprintf("T = %1.2f",(i-3)/160.)
}

# set terminal gif animate delay 1 font "Arials,16"
# set output "Solution_640_40_40.gif"
# set title "Solution of heat condactivity equation.\nP = 640; N = M = 40" 
# do for [i=3:643] {
#     splot "Solution_640_40_40.txt" u 1:2:i w l t sprintf("T = %1.3f",(i-3)/640.)
# }


# set terminal gif animate delay 0.25 font "Arials,16"
# set output "Solution_2560_80_80.gif"
# set title "Solution of heat condactivity equation.\nP = 2560; N = M = 80" 
# do for [i=3:2563] {
#     splot "Solution_2560_80_80.txt" u 1:2:i w l t sprintf("T = %1.3f",(i-3)/2560.)
# }

