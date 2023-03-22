# set terminal jpeg font "Arials,16"
# set output "Errors.jpeg"
# set xlabel "T"
# set ylabel "Error"
# set title "Max errors"
# plot [0.1:1][0:0.1]"Error_10_5_5.txt" w l lw 2 t "P = 10, N = M = 5", "Error_40_10_10.txt" w l lw 2 t "P = 40; N = M = 10", "Error_160_20_20.txt" w l lw 2 t "P = 160; N = M = 20", "Error_640_40_40.txt" w l lw 2 t "P = 640; N = M = 40", "Error_2560_80_80.txt" w l lw 2 t "P = 2560; N = M = 80" 

# set terminal jpeg font "Arials,16"
# set output "RelErrors.jpeg"
# set xlabel "T"
# set ylabel "Error"
# set title "Max Relative errors"
# plot "RelError_10_5_5.txt" w l lw 2 t "P = 10, N = M = 5", "RelError_40_10_10.txt" w l lw 2 t "P = 40; N = M = 10", "RelError_160_20_20.txt" w l lw 2 t "P = 160; N = M = 20", "RelError_640_40_40.txt" w l lw 2 t "P = 640; N = M = 40", "RelError_2560_80_80.txt" w l lw 2 t "P = 2560; N = M = 80" 


# set terminal jpeg font "Arials,16"
# set output "Sections scaled.jpeg"
# set xlabel "X"
# set ylabel "T"
# set title "Scaled Sections at T  = 0.5, Y = 0.5"
# set key font "Arials,12"

# plot [0.3:0.7][0.15:0.3]"Layer_2560_80_80.txt" u 1:3 w l lw 2 t "Exact solution", "Layer_10_5_5.txt" w l lw 2 t "P = 10, N = M = 5", "Layer_40_10_10.txt" w l lw 2 t "P = 40, N = M = 10", "Layer_160_20_20.txt" w l lw 2 t "P = 160, N = M = 20", "Layer_640_40_40.txt" w l lw 2 t "P = 640, N = M = 30", "Layer_2560_80_80.txt" w l lw 2 t "P = 2560, N = M = 80"


set terminal gif animate delay 64 font "Arials,16"
set output "AllErrors_10_5_5_s.gif"
set title "Errors of the solution of heat condactivity equation.\nP = 10, N = M = 5" 
set xlabel "X"
set ylabel "Y"
set zlabel "Error"
set pm3d
set key at graph 0.3, 2.4
set zrange [0:0.07]
set cbrange [0:0.07]
set hidden3d 
# set grid
# set key right top


do for [i=3:13] {
    splot "AllErrors_10_5_5.txt" u 1:2:i w l t sprintf("T = %1.2f",(i-3)/10.)
}

set terminal gif animate delay 16 font "Arials,16"
set output "AllErrors_40_10_10.gif"
set title "Errors of the solution of heat condactivity equation.\nP = 40; N = M = 10" 
do for [i=3:43] {
    splot "AllErrors_40_10_10.txt" u 1:2:i w l t sprintf("T = %1.2f",(i-3)/40.)
}

set terminal gif animate delay 4 font "Arials,16"
set output "AllErrors_160_20_20.gif"
set title "Errors of the solution of heat condactivity equation.\nP = 160; N = M = 20" 
do for [i=3:163] {
    splot "AllErrors_160_20_20.txt" u 1:2:i w l t sprintf("T = %1.2f",(i-3)/160.)
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

