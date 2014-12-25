./a.out < test1.txt > test1_student.txt
./a.out < test2.txt > test2_student.txt
./a.out < test3.txt > test3_student.txt
./a.out < test4.txt > test4_student.txt
./a.out < test5.txt > test5_student.txt
./a.out < test6.txt > test6_student.txt
./a.out < test7.txt > test7_student.txt
./a.out < test8.txt > test8_student.txt
./a.out < test9.txt > test9_student.txt
./a.out < test10.txt > test10_student.txt
./a.out < test11.txt > test11_student.txt
./a.out < test12.txt > test12_student.txt
./a.out < test13.txt > test13_student.txt
./a.out < test14.txt > test14_student.txt
./a.out < test15.txt > test15_student.txt
diff -q -s -i -E -Z -b -w -B test1_res.txt test1_student.txt
diff -q -s -i -E -Z -b -w -B test2_res.txt test2_student.txt
diff -q -s -i -E -Z -b -w -B test3_res.txt test3_student.txt
diff -q -s -i -E -Z -b -w -B test4_res.txt test4_student.txt
diff -q -s -i -E -Z -b -w -B test5_res.txt test5_student.txt
diff -q -s -i -E -Z -b -w -B test6_res.txt test6_student.txt
diff -q -s -i -E -Z -b -w -B test7_res.txt test7_student.txt
diff -q -s -i -E -Z -b -w -B test8_res.txt test8_student.txt
diff -q -s -i -E -Z -b -w -B test9_res.txt test9_student.txt
diff -q -s -i -E -Z -b -w -B test10_res.txt test10_student.txt
diff -q -s -i -E -Z -b -w -B test11_res.txt test11_student.txt
diff -q -s -i -E -Z -b -w -B test12_res.txt test12_student.txt
diff -q -s -i -E -Z -b -w -B test13_res.txt test13_student.txt
diff -q -s -i -E -Z -b -w -B test14_res.txt test14_student.txt
diff -q -s -i -E -Z -b -w -B test15_res.txt test15_student.txt
