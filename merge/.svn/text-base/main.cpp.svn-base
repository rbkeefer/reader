#include "pyramid.h"
#include "utils.h"
#include "mergeRectList.h"

void processArguments(int argc, char** argv);
list<BoundingRectangle*> getRectList();

int main(int argc, char** argv)
{
  processArguments(argc, argv);

  list<BoundingRectangle*> boundingRectList = getRectList();
  boundingRectList = combineTouchingRectangles(boundingRectList, 1); //  tolerance);

  dumpRectList(boundingRectList);
}

void processArguments(int argc, char** argv)
{
  for (int i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "-threshold") == 0)
    {
      threshold = atoi(argv[i+1]);
    }
    else if (strcmp(argv[i], "-accuracy") == 0)
    {
      accuracy = atoi(argv[i+1]);
    }
    else if (strcmp(argv[i], "-tolerance") == 0)
    {
      tolerance = atoi(argv[i+1]);
    }
    else if (strcmp(argv[i], "-h") == 0)
    {
      printf("Usage [-options] filename\n  -threshold [val] -tolerance [val] -accuracy [val]\n");
      exit(0);
    }
  }
}

list<BoundingRectangle*> getRectList()
{
  list<BoundingRectangle*> returnList;

  BoundingRectangle* r1 = new BoundingRectangle(1, 1, 2,12);
  returnList.push_back(r1);

  BoundingRectangle* r2 = new BoundingRectangle(5, 5, 4,5);
  returnList.push_back(r2);

  BoundingRectangle* r3 = new BoundingRectangle(3, 4, 6,7);
  returnList.push_back(r3);

  BoundingRectangle* r4 = new BoundingRectangle(6, 6, 5,5);
  returnList.push_back(r4);

  BoundingRectangle* r5 = new BoundingRectangle(6, 6, 6,17);
  returnList.push_back(r5);

  BoundingRectangle* r6 = new BoundingRectangle(7, 7, 5,5);
  returnList.push_back(r6);

  BoundingRectangle* r7 = new BoundingRectangle(4, 6, 8,10);
  returnList.push_back(r7);

  BoundingRectangle* r8 = new BoundingRectangle(3, 4, 9,10);
  returnList.push_back(r8);

  BoundingRectangle* r9 = new BoundingRectangle(9, 9, 3,3);
  returnList.push_back(r9);

  BoundingRectangle* r10 = new BoundingRectangle(9, 9, 4,8);
  returnList.push_back(r10);

  BoundingRectangle* r11 = new BoundingRectangle(10, 10, 2,3);
  returnList.push_back(r11);

  BoundingRectangle* r12 = new BoundingRectangle(3, 4, 11,13);
  returnList.push_back(r12);

  BoundingRectangle* r13 = new BoundingRectangle(12, 15, 2,5);
  returnList.push_back(r13);

  BoundingRectangle* r14 = new BoundingRectangle(12, 15, 6,6);
  returnList.push_back(r14);

  BoundingRectangle* r15 = new BoundingRectangle(9, 9, 10,13);
  returnList.push_back(r15);

  BoundingRectangle* r16 = new BoundingRectangle(5, 6, 13,14);
  returnList.push_back(r16);

  BoundingRectangle* r17 = new BoundingRectangle(1, 1, 14,16);
  returnList.push_back(r17);

  BoundingRectangle* r18 = new BoundingRectangle(4, 4, 14,14);
  returnList.push_back(r18);

  BoundingRectangle* r19 = new BoundingRectangle(13, 15, 7,10);
  returnList.push_back(r19);

  BoundingRectangle* r20 = new BoundingRectangle(12, 15, 9,9);
  returnList.push_back(r20);


return returnList;


  BoundingRectangle* r21 = new BoundingRectangle(4, 4, 15,15);
  returnList.push_back(r21);

  BoundingRectangle* r22 = new BoundingRectangle(16, 16, 2,2);
  returnList.push_back(r22);

  BoundingRectangle* r23 = new BoundingRectangle(1, 1, 18,18);
  returnList.push_back(r23);

  BoundingRectangle* r24 = new BoundingRectangle(18, 50, 4,27);
  returnList.push_back(r24);

  BoundingRectangle* r25 = new BoundingRectangle(15, 15, 11,34);
  returnList.push_back(r25);

  BoundingRectangle* r26 = new BoundingRectangle(13, 13, 14,18);
  returnList.push_back(r26);

  BoundingRectangle* r27 = new BoundingRectangle(19, 51, 2,34);
  returnList.push_back(r27);

  BoundingRectangle* r28 = new BoundingRectangle(9, 9, 18,18);
  returnList.push_back(r28);

  BoundingRectangle* r29 = new BoundingRectangle(14, 15, 15,15);
  returnList.push_back(r29);

  BoundingRectangle* r30 = new BoundingRectangle(14, 15, 17,22);
  returnList.push_back(r30);

  BoundingRectangle* r31 = new BoundingRectangle(1, 5, 23,27);
  returnList.push_back(r31);

  BoundingRectangle* r32 = new BoundingRectangle(6, 8, 23,25);
  returnList.push_back(r32);

  BoundingRectangle* r33 = new BoundingRectangle(13, 15, 20,22);
  returnList.push_back(r33);

  BoundingRectangle* r34 = new BoundingRectangle(9, 9, 25,27);
  returnList.push_back(r34);

  BoundingRectangle* r35 = new BoundingRectangle(6, 6, 26,26);
  returnList.push_back(r35);

  BoundingRectangle* r36 = new BoundingRectangle(8, 9, 26,27);
  returnList.push_back(r36);

  BoundingRectangle* r37 = new BoundingRectangle(1, 3, 28,29);
  returnList.push_back(r37);

  BoundingRectangle* r38 = new BoundingRectangle(5, 5, 28,28);
  returnList.push_back(r38);

  BoundingRectangle* r39 = new BoundingRectangle(7, 8, 28,36);
  returnList.push_back(r39);

  BoundingRectangle* r40 = new BoundingRectangle(2, 9, 30,31);
  returnList.push_back(r40);

  BoundingRectangle* r41 = new BoundingRectangle(1, 10, 31,31);
  returnList.push_back(r41);

  BoundingRectangle* r42 = new BoundingRectangle(14, 15, 28,28);
  returnList.push_back(r42);

  BoundingRectangle* r43 = new BoundingRectangle(4, 10, 32,33);
  returnList.push_back(r43);

  BoundingRectangle* r44 = new BoundingRectangle(5, 8, 34,36);
  returnList.push_back(r44);

  BoundingRectangle* r45 = new BoundingRectangle(14, 16, 32,33);
  returnList.push_back(r45);

  BoundingRectangle* r46 = new BoundingRectangle(13, 13, 33,33);
  returnList.push_back(r46);

  BoundingRectangle* r47 = new BoundingRectangle(9, 9, 35,37);
  returnList.push_back(r47);

  BoundingRectangle* r48 = new BoundingRectangle(4, 6, 36,37);
  returnList.push_back(r48);

  BoundingRectangle* r49 = new BoundingRectangle(13, 13, 34,34);
  returnList.push_back(r49);

  BoundingRectangle* r50 = new BoundingRectangle(16, 16, 34,54);
  returnList.push_back(r50);

  BoundingRectangle* r51 = new BoundingRectangle(8, 9, 37,37);
  returnList.push_back(r51);

  BoundingRectangle* r52 = new BoundingRectangle(15, 16, 36,36);
  returnList.push_back(r52);

  BoundingRectangle* r53 = new BoundingRectangle(8, 9, 39,40);
  returnList.push_back(r53);

  BoundingRectangle* r54 = new BoundingRectangle(19, 33, 35,49);
  returnList.push_back(r54);

  BoundingRectangle* r55 = new BoundingRectangle(2, 3, 40,42);
  returnList.push_back(r55);

  BoundingRectangle* r56 = new BoundingRectangle(10, 10, 39,40);
  returnList.push_back(r56);

  BoundingRectangle* r57 = new BoundingRectangle(5, 6, 40,44);
  returnList.push_back(r57);

  BoundingRectangle* r58 = new BoundingRectangle(15, 16, 38,38);
  returnList.push_back(r58);

  BoundingRectangle* r59 = new BoundingRectangle(4, 6, 41,43);
  returnList.push_back(r59);

  BoundingRectangle* r60 = new BoundingRectangle(8, 9, 41,42);
  returnList.push_back(r60);

  BoundingRectangle* r61 = new BoundingRectangle(3, 3, 43,43);
  returnList.push_back(r61);

  BoundingRectangle* r62 = new BoundingRectangle(7, 8, 43,44);
  returnList.push_back(r62);

  BoundingRectangle* r63 = new BoundingRectangle(2, 3, 44,46);
  returnList.push_back(r63);

  BoundingRectangle* r64 = new BoundingRectangle(9, 9, 44,44);
  returnList.push_back(r64);

  BoundingRectangle* r65 = new BoundingRectangle(10, 10, 44,44);
  returnList.push_back(r65);

  BoundingRectangle* r66 = new BoundingRectangle(9, 9, 45,48);
  returnList.push_back(r66);

  BoundingRectangle* r67 = new BoundingRectangle(5, 7, 46,48);
  returnList.push_back(r67);

  BoundingRectangle* r68 = new BoundingRectangle(8, 9, 46,48);
  returnList.push_back(r68);

  BoundingRectangle* r69 = new BoundingRectangle(4, 6, 48,50);
  returnList.push_back(r69);

  BoundingRectangle* r70 = new BoundingRectangle(34, 42, 35,44);
  returnList.push_back(r70);

  BoundingRectangle* r71 = new BoundingRectangle(3, 6, 49,50);
  returnList.push_back(r71);

  BoundingRectangle* r72 = new BoundingRectangle(7, 9, 50,54);
  returnList.push_back(r72);

  BoundingRectangle* r73 = new BoundingRectangle(5, 8, 51,54);
  returnList.push_back(r73);

  BoundingRectangle* r74 = new BoundingRectangle(13, 13, 50,51);
  returnList.push_back(r74);

  BoundingRectangle* r75 = new BoundingRectangle(52, 54, 2,3);
  returnList.push_back(r75);

  BoundingRectangle* r76 = new BoundingRectangle(4, 9, 52,53);
  returnList.push_back(r76);

  BoundingRectangle* r77 = new BoundingRectangle(52, 52, 5,8);
  returnList.push_back(r77);

  BoundingRectangle* r78 = new BoundingRectangle(52, 53, 10,12);
  returnList.push_back(r78);

  BoundingRectangle* r79 = new BoundingRectangle(19, 33, 50,53);
  returnList.push_back(r79);

  BoundingRectangle* r80 = new BoundingRectangle(14, 14, 52,75);
  returnList.push_back(r80);

  BoundingRectangle* r81 = new BoundingRectangle(52, 55, 14,17);
  returnList.push_back(r81);

  BoundingRectangle* r82 = new BoundingRectangle(53, 54, 13,19);
  returnList.push_back(r82);

  BoundingRectangle* r83 = new BoundingRectangle(52, 54, 18,19);
  returnList.push_back(r83);

  BoundingRectangle* r84 = new BoundingRectangle(15, 16, 53,54);
  returnList.push_back(r84);

  BoundingRectangle* r85 = new BoundingRectangle(55, 71, 3,3);
  returnList.push_back(r85);

  BoundingRectangle* r86 = new BoundingRectangle(4, 8, 55,55);
  returnList.push_back(r86);

  BoundingRectangle* r87 = new BoundingRectangle(43, 48, 35,37);
  returnList.push_back(r87);

  BoundingRectangle* r88 = new BoundingRectangle(55, 65, 10,10);
  returnList.push_back(r88);

  BoundingRectangle* r89 = new BoundingRectangle(5, 5, 56,56);
  returnList.push_back(r89);

  BoundingRectangle* r90 = new BoundingRectangle(13, 15, 55,56);
  returnList.push_back(r90);

  BoundingRectangle* r91 = new BoundingRectangle(55, 65, 13,17);
  returnList.push_back(r91);

  BoundingRectangle* r92 = new BoundingRectangle(35, 35, 45,47);
  returnList.push_back(r92);

  BoundingRectangle* r93 = new BoundingRectangle(57, 70, 2,4);
  returnList.push_back(r93);

  BoundingRectangle* r94 = new BoundingRectangle(19, 31, 54,66);
  returnList.push_back(r94);

  BoundingRectangle* r95 = new BoundingRectangle(52, 52, 25,26);
  returnList.push_back(r95);

  BoundingRectangle* r96 = new BoundingRectangle(57, 65, 9,10);
  returnList.push_back(r96);

  BoundingRectangle* r97 = new BoundingRectangle(34, 34, 47,47);
  returnList.push_back(r97);

  BoundingRectangle* r98 = new BoundingRectangle(2, 2, 58,64);
  returnList.push_back(r98);

  BoundingRectangle* r99 = new BoundingRectangle(43, 45, 39,41);
  returnList.push_back(r99);

  BoundingRectangle* r100 = new BoundingRectangle(44, 49, 38,43);
  returnList.push_back(r100);

  BoundingRectangle* r101 = new BoundingRectangle(55, 61, 19,19);
  returnList.push_back(r101);

  BoundingRectangle* r102 = new BoundingRectangle(5, 6, 58,63);
  returnList.push_back(r102);

  BoundingRectangle* r103 = new BoundingRectangle(57, 60, 12,20);
  returnList.push_back(r103);

  BoundingRectangle* r104 = new BoundingRectangle(37, 44, 45,45);
  returnList.push_back(r104);

  BoundingRectangle* r105 = new BoundingRectangle(9, 11, 58,63);
  returnList.push_back(r105);

  BoundingRectangle* r106 = new BoundingRectangle(34, 34, 48,48);
  returnList.push_back(r106);

  BoundingRectangle* r107 = new BoundingRectangle(15, 15, 57,124);
  returnList.push_back(r107);

  BoundingRectangle* r108 = new BoundingRectangle(3, 3, 59,63);
  returnList.push_back(r108);

  BoundingRectangle* r109 = new BoundingRectangle(4, 11, 59,60);
  returnList.push_back(r109);

  BoundingRectangle* r110 = new BoundingRectangle(59, 71, 7,7);
  returnList.push_back(r110);

  BoundingRectangle* r111 = new BoundingRectangle(13, 15, 58,68);
  returnList.push_back(r111);

  BoundingRectangle* r112 = new BoundingRectangle(56, 60, 20,20);
  returnList.push_back(r112);

  BoundingRectangle* r113 = new BoundingRectangle(53, 53, 27,29);
  returnList.push_back(r113);

  BoundingRectangle* r114 = new BoundingRectangle(52, 57, 29,29);
  returnList.push_back(r114);

  BoundingRectangle* r115 = new BoundingRectangle(38, 41, 46,49);
  returnList.push_back(r115);

  BoundingRectangle* r116 = new BoundingRectangle(59, 65, 11,18);
  returnList.push_back(r116);

  BoundingRectangle* r117 = new BoundingRectangle(43, 45, 42,44);
  returnList.push_back(r117);

  BoundingRectangle* r118 = new BoundingRectangle(56, 56, 22,23);
  returnList.push_back(r118);

  BoundingRectangle* r119 = new BoundingRectangle(60, 63, 6,7);
  returnList.push_back(r119);

  BoundingRectangle* r120 = new BoundingRectangle(36, 39, 49,52);
  returnList.push_back(r120);

  BoundingRectangle* r121 = new BoundingRectangle(35, 41, 50,51);
  returnList.push_back(r121);

  BoundingRectangle* r122 = new BoundingRectangle(50, 50, 35,35);
  returnList.push_back(r122);

  BoundingRectangle* r123 = new BoundingRectangle(52, 52, 32,32);
  returnList.push_back(r123);

  BoundingRectangle* r124 = new BoundingRectangle(61, 65, 5,9);
  returnList.push_back(r124);

  BoundingRectangle* r125 = new BoundingRectangle(34, 42, 51,51);
  returnList.push_back(r125);

  BoundingRectangle* r126 = new BoundingRectangle(49, 58, 37,43);
  returnList.push_back(r126);

  BoundingRectangle* r127 = new BoundingRectangle(52, 52, 33,34);
  returnList.push_back(r127);

  BoundingRectangle* r128 = new BoundingRectangle(58, 59, 21,21);
  returnList.push_back(r128);

  BoundingRectangle* r129 = new BoundingRectangle(55, 56, 28,31);
  returnList.push_back(r129);

  BoundingRectangle* r130 = new BoundingRectangle(54, 55, 30,31);
  returnList.push_back(r130);

  BoundingRectangle* r131 = new BoundingRectangle(53, 54, 32,32);
  returnList.push_back(r131);

  BoundingRectangle* r132 = new BoundingRectangle(4, 11, 62,63);
  returnList.push_back(r132);

  BoundingRectangle* r133 = new BoundingRectangle(34, 40, 52,52);
  returnList.push_back(r133);

  BoundingRectangle* r134 = new BoundingRectangle(12, 15, 61,61);
  returnList.push_back(r134);

  BoundingRectangle* r135 = new BoundingRectangle(42, 42, 46,49);
  returnList.push_back(r135);

  BoundingRectangle* r136 = new BoundingRectangle(51, 58, 36,45);
  returnList.push_back(r136);

  BoundingRectangle* r137 = new BoundingRectangle(32, 32, 54,65);
  returnList.push_back(r137);

  BoundingRectangle* r138 = new BoundingRectangle(34, 35, 53,54);
  returnList.push_back(r138);

  BoundingRectangle* r139 = new BoundingRectangle(57, 83, 27,27);
  returnList.push_back(r139);

  BoundingRectangle* r140 = new BoundingRectangle(54, 54, 33,47);
  returnList.push_back(r140);

  BoundingRectangle* r141 = new BoundingRectangle(18, 31, 61,83);
  returnList.push_back(r141);

  BoundingRectangle* r142 = new BoundingRectangle(46, 46, 44,44);
  returnList.push_back(r142);

  BoundingRectangle* r143 = new BoundingRectangle(64, 70, 1,5);
  returnList.push_back(r143);

  BoundingRectangle* r144 = new BoundingRectangle(36, 39, 53,54);
  returnList.push_back(r144);

  BoundingRectangle* r145 = new BoundingRectangle(12, 15, 63,63);
  returnList.push_back(r145);

  BoundingRectangle* r146 = new BoundingRectangle(33, 35, 55,64);
  returnList.push_back(r146);

  BoundingRectangle* r147 = new BoundingRectangle(6, 8, 64,68);
  returnList.push_back(r147);

  BoundingRectangle* r148 = new BoundingRectangle(46, 46, 45,50);
  returnList.push_back(r148);

  BoundingRectangle* r149 = new BoundingRectangle(47, 47, 44,44);
  returnList.push_back(r149);

  BoundingRectangle* r150 = new BoundingRectangle(58, 83, 28,28);
  returnList.push_back(r150);

  BoundingRectangle* r151 = new BoundingRectangle(57, 83, 30,31);
  returnList.push_back(r151);

  BoundingRectangle* r152 = new BoundingRectangle(59, 61, 26,28);
  returnList.push_back(r152);

  BoundingRectangle* r153 = new BoundingRectangle(55, 57, 34,47);
  returnList.push_back(r153);

  BoundingRectangle* r154 = new BoundingRectangle(10, 11, 64,64);
  returnList.push_back(r154);

  BoundingRectangle* r155 = new BoundingRectangle(62, 68, 20,21);
  returnList.push_back(r155);

  BoundingRectangle* r156 = new BoundingRectangle(5, 8, 65,68);
  returnList.push_back(r156);

  BoundingRectangle* r157 = new BoundingRectangle(59, 61, 29,33);
  returnList.push_back(r157);

  BoundingRectangle* r158 = new BoundingRectangle(63, 66, 19,22);
  returnList.push_back(r158);

  BoundingRectangle* r159 = new BoundingRectangle(61, 62, 25,28);
  returnList.push_back(r159);

  BoundingRectangle* r160 = new BoundingRectangle(4, 9, 66,67);
  returnList.push_back(r160);

  BoundingRectangle* r161 = new BoundingRectangle(58, 63, 32,33);
  returnList.push_back(r161);

  BoundingRectangle* r162 = new BoundingRectangle(66, 71, 6,9);
  returnList.push_back(r162);

  BoundingRectangle* r163 = new BoundingRectangle(37, 38, 55,55);
  returnList.push_back(r163);

  BoundingRectangle* r164 = new BoundingRectangle(47, 47, 47,73);
  returnList.push_back(r164);

  BoundingRectangle* r165 = new BoundingRectangle(62, 62, 24,24);
  returnList.push_back(r165);

  BoundingRectangle* r166 = new BoundingRectangle(36, 36, 56,83);
  returnList.push_back(r166);

  BoundingRectangle* r167 = new BoundingRectangle(42, 42, 52,52);
  returnList.push_back(r167);

  BoundingRectangle* r168 = new BoundingRectangle(63, 63, 23,23);
  returnList.push_back(r168);

  BoundingRectangle* r169 = new BoundingRectangle(66, 67, 12,13);
  returnList.push_back(r169);

  BoundingRectangle* r170 = new BoundingRectangle(63, 63, 24,24);
  returnList.push_back(r170);

  BoundingRectangle* r171 = new BoundingRectangle(66, 67, 14,14);
  returnList.push_back(r171);

  BoundingRectangle* r172 = new BoundingRectangle(38, 51, 56,57);
  returnList.push_back(r172);

  BoundingRectangle* r173 = new BoundingRectangle(58, 58, 35,35);
  returnList.push_back(r173);

  BoundingRectangle* r174 = new BoundingRectangle(67, 68, 10,11);
  returnList.push_back(r174);

  BoundingRectangle* r175 = new BoundingRectangle(37, 37, 57,57);
  returnList.push_back(r175);

  BoundingRectangle* r176 = new BoundingRectangle(40, 50, 55,65);
  returnList.push_back(r176);

  BoundingRectangle* r177 = new BoundingRectangle(64, 65, 23,23);
  returnList.push_back(r177);

  BoundingRectangle* r178 = new BoundingRectangle(63, 68, 26,31);
  returnList.push_back(r178);

  BoundingRectangle* r179 = new BoundingRectangle(66, 68, 17,19);
  returnList.push_back(r179);

  BoundingRectangle* r180 = new BoundingRectangle(48, 48, 49,50);
  returnList.push_back(r180);

  BoundingRectangle* r181 = new BoundingRectangle(59, 66, 35,35);
  returnList.push_back(r181);

  BoundingRectangle* r182 = new BoundingRectangle(67, 68, 15,21);
  returnList.push_back(r182);

  BoundingRectangle* r183 = new BoundingRectangle(37, 37, 58,83);
  returnList.push_back(r183);

  BoundingRectangle* r184 = new BoundingRectangle(60, 63, 34,36);
  returnList.push_back(r184);

  BoundingRectangle* r185 = new BoundingRectangle(43, 45, 54,76);
  returnList.push_back(r185);

  BoundingRectangle* r186 = new BoundingRectangle(68, 68, 12,12);
  returnList.push_back(r186);

  BoundingRectangle* r187 = new BoundingRectangle(4, 5, 69,77);
  returnList.push_back(r187);

  BoundingRectangle* r188 = new BoundingRectangle(52, 59, 46,46);
  returnList.push_back(r188);

  BoundingRectangle* r189 = new BoundingRectangle(8, 8, 69,71);
  returnList.push_back(r189);

  BoundingRectangle* r190 = new BoundingRectangle(59, 61, 37,38);
  returnList.push_back(r190);

  BoundingRectangle* r191 = new BoundingRectangle(69, 69, 10,11);
  returnList.push_back(r191);

  BoundingRectangle* r192 = new BoundingRectangle(39, 51, 58,61);
  returnList.push_back(r192);

  BoundingRectangle* r193 = new BoundingRectangle(50, 55, 49,49);
  returnList.push_back(r193);

  BoundingRectangle* r194 = new BoundingRectangle(69, 70, 13,13);
  returnList.push_back(r194);

  BoundingRectangle* r195 = new BoundingRectangle(66, 67, 24,32);
  returnList.push_back(r195);

  BoundingRectangle* r196 = new BoundingRectangle(6, 9, 70,71);
  returnList.push_back(r196);

  BoundingRectangle* r197 = new BoundingRectangle(69, 71, 16,18);
  returnList.push_back(r197);

  BoundingRectangle* r198 = new BoundingRectangle(53, 59, 47,47);
  returnList.push_back(r198);

  BoundingRectangle* r199 = new BoundingRectangle(70, 70, 11,14);
  returnList.push_back(r199);

  BoundingRectangle* r200 = new BoundingRectangle(38, 52, 60,60);
  returnList.push_back(r200);

  BoundingRectangle* r201 = new BoundingRectangle(71, 71, 4,10);
  returnList.push_back(r201);

  BoundingRectangle* r202 = new BoundingRectangle(59, 62, 40,43);
  returnList.push_back(r202);

  BoundingRectangle* r203 = new BoundingRectangle(51, 56, 50,51);
  returnList.push_back(r203);

  BoundingRectangle* r204 = new BoundingRectangle(60, 60, 39,43);
  returnList.push_back(r204);

  BoundingRectangle* r205 = new BoundingRectangle(69, 69, 19,19);
  returnList.push_back(r205);

  BoundingRectangle* r206 = new BoundingRectangle(68, 74, 23,23);
  returnList.push_back(r206);

  BoundingRectangle* r207 = new BoundingRectangle(38, 51, 61,61);
  returnList.push_back(r207);

  BoundingRectangle* r208 = new BoundingRectangle(72, 74, 5,6);
  returnList.push_back(r208);

  BoundingRectangle* r209 = new BoundingRectangle(48, 50, 54,73);
  returnList.push_back(r209);

  BoundingRectangle* r210 = new BoundingRectangle(69, 74, 22,23);
  returnList.push_back(r210);

  BoundingRectangle* r211 = new BoundingRectangle(65, 68, 32,32);
  returnList.push_back(r211);

  BoundingRectangle* r212 = new BoundingRectangle(68, 68, 25,33);
  returnList.push_back(r212);

  BoundingRectangle* r213 = new BoundingRectangle(71, 74, 15,16);
  returnList.push_back(r213);

  BoundingRectangle* r214 = new BoundingRectangle(38, 50, 62,73);
  returnList.push_back(r214);

  BoundingRectangle* r215 = new BoundingRectangle(73, 74, 1,2);
  returnList.push_back(r215);

  BoundingRectangle* r216 = new BoundingRectangle(2, 9, 73,74);
  returnList.push_back(r216);

  BoundingRectangle* r217 = new BoundingRectangle(63, 66, 37,37);
  returnList.push_back(r217);

  BoundingRectangle* r218 = new BoundingRectangle(73, 74, 3,7);
  returnList.push_back(r218);

  BoundingRectangle* r219 = new BoundingRectangle(34, 45, 65,76);
  returnList.push_back(r219);

  BoundingRectangle* r220 = new BoundingRectangle(65, 65, 34,35);
  returnList.push_back(r220);

  BoundingRectangle* r221 = new BoundingRectangle(64, 64, 36,38);
  returnList.push_back(r221);

  BoundingRectangle* r222 = new BoundingRectangle(52, 65, 52,52);
  returnList.push_back(r222);

  BoundingRectangle* r223 = new BoundingRectangle(73, 74, 9,49);
  returnList.push_back(r223);

  BoundingRectangle* r224 = new BoundingRectangle(59, 59, 44,48);
  returnList.push_back(r224);

  BoundingRectangle* r225 = new BoundingRectangle(69, 74, 26,31);
  returnList.push_back(r225);

  BoundingRectangle* r226 = new BoundingRectangle(72, 74, 17,18);
  returnList.push_back(r226);

  BoundingRectangle* r227 = new BoundingRectangle(70, 74, 24,31);
  returnList.push_back(r227);

  BoundingRectangle* r228 = new BoundingRectangle(1, 9, 74,74);
  returnList.push_back(r228);

  BoundingRectangle* r229 = new BoundingRectangle(71, 74, 21,33);
  returnList.push_back(r229);

  BoundingRectangle* r230 = new BoundingRectangle(74, 74, 8,84);
  returnList.push_back(r230);

  BoundingRectangle* r231 = new BoundingRectangle(72, 74, 20,33);
  returnList.push_back(r231);

  BoundingRectangle* r232 = new BoundingRectangle(51, 51, 55,55);
  returnList.push_back(r232);

  BoundingRectangle* r233 = new BoundingRectangle(75, 75, 1,2);
  returnList.push_back(r233);

  BoundingRectangle* r234 = new BoundingRectangle(32, 32, 68,83);
  returnList.push_back(r234);

  BoundingRectangle* r235 = new BoundingRectangle(63, 63, 41,45);
  returnList.push_back(r235);

  BoundingRectangle* r236 = new BoundingRectangle(66, 66, 36,37);
  returnList.push_back(r236);

  BoundingRectangle* r237 = new BoundingRectangle(6, 8, 75,76);
  returnList.push_back(r237);

  BoundingRectangle* r238 = new BoundingRectangle(65, 65, 38,38);
  returnList.push_back(r238);

  BoundingRectangle* r239 = new BoundingRectangle(52, 53, 55,55);
  returnList.push_back(r239);

  BoundingRectangle* r240 = new BoundingRectangle(75, 80, 11,14);
  returnList.push_back(r240);

  BoundingRectangle* r241 = new BoundingRectangle(62, 66, 44,44);
  returnList.push_back(r241);

  BoundingRectangle* r242 = new BoundingRectangle(55, 58, 53,53);
  returnList.push_back(r242);

  BoundingRectangle* r243 = new BoundingRectangle(33, 39, 69,83);
  returnList.push_back(r243);

  BoundingRectangle* r244 = new BoundingRectangle(57, 58, 51,55);
  returnList.push_back(r244);

  BoundingRectangle* r245 = new BoundingRectangle(9, 9, 76,77);
  returnList.push_back(r245);

  BoundingRectangle* r246 = new BoundingRectangle(64, 64, 42,45);
  returnList.push_back(r246);

  BoundingRectangle* r247 = new BoundingRectangle(60, 62, 48,49);
  returnList.push_back(r247);

  BoundingRectangle* r248 = new BoundingRectangle(62, 62, 46,46);
  returnList.push_back(r248);

  BoundingRectangle* r249 = new BoundingRectangle(7, 9, 77,77);
  returnList.push_back(r249);

  BoundingRectangle* r250 = new BoundingRectangle(55, 55, 55,55);
  returnList.push_back(r250);

  BoundingRectangle* r251 = new BoundingRectangle(54, 55, 56,56);
  returnList.push_back(r251);

  BoundingRectangle* r252 = new BoundingRectangle(65, 65, 43,46);
  returnList.push_back(r252);

  BoundingRectangle* r253 = new BoundingRectangle(78, 79, 1,1);
  returnList.push_back(r253);

  BoundingRectangle* r254 = new BoundingRectangle(56, 61, 55,55);
  returnList.push_back(r254);

  BoundingRectangle* r255 = new BoundingRectangle(52, 52, 59,60);
  returnList.push_back(r255);

  BoundingRectangle* r256 = new BoundingRectangle(70, 71, 36,38);
  returnList.push_back(r256);

  BoundingRectangle* r257 = new BoundingRectangle(71, 71, 34,42);
  returnList.push_back(r257);

  BoundingRectangle* r258 = new BoundingRectangle(60, 62, 51,54);
  returnList.push_back(r258);

  BoundingRectangle* r259 = new BoundingRectangle(69, 71, 38,38);
  returnList.push_back(r259);

  BoundingRectangle* r260 = new BoundingRectangle(61, 63, 50,52);
  returnList.push_back(r260);

  BoundingRectangle* r261 = new BoundingRectangle(2, 3, 79,87);
  returnList.push_back(r261);

  BoundingRectangle* r262 = new BoundingRectangle(5, 7, 79,82);
  returnList.push_back(r262);

  BoundingRectangle* r263 = new BoundingRectangle(55, 56, 57,57);
  returnList.push_back(r263);

  BoundingRectangle* r264 = new BoundingRectangle(66, 67, 45,47);
  returnList.push_back(r264);

  BoundingRectangle* r265 = new BoundingRectangle(12, 12, 79,85);
  returnList.push_back(r265);

  BoundingRectangle* r266 = new BoundingRectangle(59, 63, 54,54);
  returnList.push_back(r266);

  BoundingRectangle* r267 = new BoundingRectangle(1, 9, 80,82);
  returnList.push_back(r267);

  BoundingRectangle* r268 = new BoundingRectangle(76, 83, 26,31);
  returnList.push_back(r268);

  BoundingRectangle* r269 = new BoundingRectangle(75, 77, 29,31);
  returnList.push_back(r269);

  BoundingRectangle* r270 = new BoundingRectangle(58, 64, 56,57);
  returnList.push_back(r270);

  BoundingRectangle* r271 = new BoundingRectangle(77, 83, 24,31);
  returnList.push_back(r271);

  BoundingRectangle* r272 = new BoundingRectangle(64, 64, 50,52);
  returnList.push_back(r272);

  BoundingRectangle* r273 = new BoundingRectangle(78, 83, 23,31);
  returnList.push_back(r273);

  BoundingRectangle* r274 = new BoundingRectangle(75, 76, 32,84);
  returnList.push_back(r274);

  BoundingRectangle* r275 = new BoundingRectangle(72, 83, 39,39);
  returnList.push_back(r275);

  BoundingRectangle* r276 = new BoundingRectangle(81, 83, 12,12);
  returnList.push_back(r276);

  BoundingRectangle* r277 = new BoundingRectangle(79, 83, 22,33);
  returnList.push_back(r277);

  BoundingRectangle* r278 = new BoundingRectangle(81, 81, 14,14);
  returnList.push_back(r278);

  BoundingRectangle* r279 = new BoundingRectangle(63, 63, 53,60);
  returnList.push_back(r279);

  BoundingRectangle* r280 = new BoundingRectangle(80, 83, 20,36);
  returnList.push_back(r280);

  BoundingRectangle* r281 = new BoundingRectangle(65, 65, 51,51);
  returnList.push_back(r281);

  BoundingRectangle* r282 = new BoundingRectangle(59, 67, 58,58);
  returnList.push_back(r282);

  BoundingRectangle* r283 = new BoundingRectangle(66, 66, 50,50);
  returnList.push_back(r283);

  BoundingRectangle* r284 = new BoundingRectangle(82, 83, 13,13);
  returnList.push_back(r284);

  BoundingRectangle* r285 = new BoundingRectangle(5, 5, 83,94);
  returnList.push_back(r285);

  BoundingRectangle* r286 = new BoundingRectangle(81, 83, 19,67);
  returnList.push_back(r286);

  BoundingRectangle* r287 = new BoundingRectangle(8, 9, 83,84);
  returnList.push_back(r287);

  BoundingRectangle* r288 = new BoundingRectangle(66, 66, 51,51);
  returnList.push_back(r288);

  BoundingRectangle* r289 = new BoundingRectangle(67, 69, 50,50);
  returnList.push_back(r289);

  BoundingRectangle* r290 = new BoundingRectangle(77, 78, 33,34);
  returnList.push_back(r290);

  BoundingRectangle* r291 = new BoundingRectangle(82, 83, 18,67);
  returnList.push_back(r291);

  BoundingRectangle* r292 = new BoundingRectangle(1, 3, 84,85);
  returnList.push_back(r292);

  BoundingRectangle* r293 = new BoundingRectangle(60, 65, 59,60);
  returnList.push_back(r293);

  BoundingRectangle* r294 = new BoundingRectangle(83, 83, 14,14);
  returnList.push_back(r294);

  BoundingRectangle* r295 = new BoundingRectangle(6, 9, 84,84);
  returnList.push_back(r295);

  BoundingRectangle* r296 = new BoundingRectangle(64, 64, 55,55);
  returnList.push_back(r296);

  BoundingRectangle* r297 = new BoundingRectangle(65, 65, 54,55);
  returnList.push_back(r297);

  BoundingRectangle* r298 = new BoundingRectangle(77, 78, 35,80);
  returnList.push_back(r298);

  BoundingRectangle* r299 = new BoundingRectangle(83, 83, 17,67);
  returnList.push_back(r299);

  BoundingRectangle* r300 = new BoundingRectangle(67, 69, 52,52);
  returnList.push_back(r300);

  BoundingRectangle* r301 = new BoundingRectangle(68, 69, 51,52);
  returnList.push_back(r301);

  BoundingRectangle* r302 = new BoundingRectangle(4, 6, 85,87);
  returnList.push_back(r302);

  BoundingRectangle* r303 = new BoundingRectangle(7, 7, 85,87);
  returnList.push_back(r303);

  BoundingRectangle* r304 = new BoundingRectangle(51, 51, 69,81);
  returnList.push_back(r304);

  BoundingRectangle* r305 = new BoundingRectangle(8, 8, 86,102);
  returnList.push_back(r305);

  BoundingRectangle* r306 = new BoundingRectangle(65, 67, 57,59);
  returnList.push_back(r306);

  BoundingRectangle* r307 = new BoundingRectangle(40, 40, 77,77);
  returnList.push_back(r307);

  BoundingRectangle* r308 = new BoundingRectangle(18, 20, 85,87);
  returnList.push_back(r308);

  BoundingRectangle* r309 = new BoundingRectangle(61, 62, 62,63);
  returnList.push_back(r309);

  BoundingRectangle* r310 = new BoundingRectangle(62, 62, 61,63);
  returnList.push_back(r310);

  BoundingRectangle* r311 = new BoundingRectangle(46, 46, 74,76);
  returnList.push_back(r311);

  BoundingRectangle* r312 = new BoundingRectangle(52, 57, 70,75);
  returnList.push_back(r312);

  BoundingRectangle* r313 = new BoundingRectangle(41, 44, 77,77);
  returnList.push_back(r313);

  BoundingRectangle* r314 = new BoundingRectangle(79, 79, 37,71);
  returnList.push_back(r314);

  BoundingRectangle* r315 = new BoundingRectangle(9, 9, 87,87);
  returnList.push_back(r315);

  BoundingRectangle* r316 = new BoundingRectangle(40, 40, 78,78);
  returnList.push_back(r316);

  BoundingRectangle* r317 = new BoundingRectangle(59, 61, 65,65);
  returnList.push_back(r317);

  BoundingRectangle* r318 = new BoundingRectangle(12, 12, 87,124);
  returnList.push_back(r318);

  BoundingRectangle* r319 = new BoundingRectangle(4, 5, 88,94);
  returnList.push_back(r319);

  BoundingRectangle* r320 = new BoundingRectangle(24, 24, 85,103);
  returnList.push_back(r320);

  BoundingRectangle* r321 = new BoundingRectangle(64, 64, 61,61);
  returnList.push_back(r321);

  BoundingRectangle* r322 = new BoundingRectangle(80, 83, 38,67);
  returnList.push_back(r322);

  BoundingRectangle* r323 = new BoundingRectangle(42, 43, 78,81);
  returnList.push_back(r323);

  BoundingRectangle* r324 = new BoundingRectangle(57, 58, 68,74);
  returnList.push_back(r324);

  BoundingRectangle* r325 = new BoundingRectangle(49, 53, 74,74);
  returnList.push_back(r325);

  BoundingRectangle* r326 = new BoundingRectangle(22, 24, 86,86);
  returnList.push_back(r326);

  BoundingRectangle* r327 = new BoundingRectangle(56, 59, 69,72);
  returnList.push_back(r327);

  BoundingRectangle* r328 = new BoundingRectangle(41, 42, 79,83);
  returnList.push_back(r328);

  BoundingRectangle* r329 = new BoundingRectangle(89, 94, 1,4);
  returnList.push_back(r329);

  BoundingRectangle* r330 = new BoundingRectangle(73, 83, 51,52);
  returnList.push_back(r330);

  BoundingRectangle* r331 = new BoundingRectangle(88, 94, 14,14);
  returnList.push_back(r331);

  BoundingRectangle* r332 = new BoundingRectangle(89, 90, 5,34);
  returnList.push_back(r332);

  BoundingRectangle* r333 = new BoundingRectangle(6, 8, 89,91);
  returnList.push_back(r333);

  BoundingRectangle* r334 = new BoundingRectangle(40, 42, 80,83);
  returnList.push_back(r334);

  BoundingRectangle* r335 = new BoundingRectangle(9, 9, 89,89);
  returnList.push_back(r335);

  BoundingRectangle* r336 = new BoundingRectangle(49, 52, 75,76);
  returnList.push_back(r336);

  BoundingRectangle* r337 = new BoundingRectangle(88, 96, 17,17);
  returnList.push_back(r337);

  BoundingRectangle* r338 = new BoundingRectangle(61, 66, 66,69);
  returnList.push_back(r338);

  BoundingRectangle* r339 = new BoundingRectangle(23, 24, 87,103);
  returnList.push_back(r339);

  BoundingRectangle* r340 = new BoundingRectangle(19, 20, 88,102);
  returnList.push_back(r340);

  BoundingRectangle* r341 = new BoundingRectangle(45, 49, 78,82);
  returnList.push_back(r341);

  BoundingRectangle* r342 = new BoundingRectangle(88, 93, 20,21);
  returnList.push_back(r342);

  BoundingRectangle* r343 = new BoundingRectangle(44, 49, 79,83);
  returnList.push_back(r343);

  BoundingRectangle* r344 = new BoundingRectangle(31, 32, 85,86);
  returnList.push_back(r344);

  BoundingRectangle* r345 = new BoundingRectangle(48, 49, 77,83);
  returnList.push_back(r345);

  BoundingRectangle* r346 = new BoundingRectangle(18, 20, 89,89);
  returnList.push_back(r346);

  BoundingRectangle* r347 = new BoundingRectangle(26, 27, 87,104);
  returnList.push_back(r347);

  BoundingRectangle* r348 = new BoundingRectangle(3, 8, 91,91);
  returnList.push_back(r348);

  BoundingRectangle* r349 = new BoundingRectangle(33, 33, 85,86);
  returnList.push_back(r349);

  BoundingRectangle* r350 = new BoundingRectangle(91, 94, 6,14);
  returnList.push_back(r350);

  BoundingRectangle* r351 = new BoundingRectangle(73, 83, 55,67);
  returnList.push_back(r351);

  BoundingRectangle* r352 = new BoundingRectangle(25, 27, 88,93);
  returnList.push_back(r352);

  BoundingRectangle* r353 = new BoundingRectangle(88, 93, 25,25);
  returnList.push_back(r353);

  BoundingRectangle* r354 = new BoundingRectangle(22, 27, 89,90);
  returnList.push_back(r354);

  BoundingRectangle* r355 = new BoundingRectangle(92, 94, 5,14);
  returnList.push_back(r355);

  BoundingRectangle* r356 = new BoundingRectangle(6, 8, 92,94);
  returnList.push_back(r356);

  BoundingRectangle* r357 = new BoundingRectangle(91, 93, 15,58);
  returnList.push_back(r357);

  BoundingRectangle* r358 = new BoundingRectangle(31, 32, 87,88);
  returnList.push_back(r358);

  BoundingRectangle* r359 = new BoundingRectangle(50, 53, 78,81);
  returnList.push_back(r359);

  BoundingRectangle* r360 = new BoundingRectangle(53, 53, 76,81);
  returnList.push_back(r360);

  BoundingRectangle* r361 = new BoundingRectangle(52, 53, 77,81);
  returnList.push_back(r361);

  BoundingRectangle* r362 = new BoundingRectangle(88, 93, 30,31);
  returnList.push_back(r362);

  BoundingRectangle* r363 = new BoundingRectangle(3, 8, 93,93);
  returnList.push_back(r363);

  BoundingRectangle* r364 = new BoundingRectangle(34, 35, 87,102);
  returnList.push_back(r364);

  BoundingRectangle* r365 = new BoundingRectangle(43, 49, 83,83);
  returnList.push_back(r365);

  BoundingRectangle* r366 = new BoundingRectangle(61, 63, 71,73);
  returnList.push_back(r366);

  BoundingRectangle* r367 = new BoundingRectangle(67, 71, 66,68);
  returnList.push_back(r367);

  BoundingRectangle* r368 = new BoundingRectangle(88, 93, 34,34);
  returnList.push_back(r368);

  BoundingRectangle* r369 = new BoundingRectangle(60, 62, 73,75);
  returnList.push_back(r369);

  BoundingRectangle* r370 = new BoundingRectangle(29, 29, 90,90);
  returnList.push_back(r370);

  BoundingRectangle* r371 = new BoundingRectangle(32, 32, 89,95);
  returnList.push_back(r371);

  BoundingRectangle* r372 = new BoundingRectangle(18, 20, 93,93);
  returnList.push_back(r372);

  BoundingRectangle* r373 = new BoundingRectangle(30, 30, 90,90);
  returnList.push_back(r373);

  BoundingRectangle* r374 = new BoundingRectangle(7, 8, 95,102);
  returnList.push_back(r374);

  BoundingRectangle* r375 = new BoundingRectangle(94, 96, 16,20);
  returnList.push_back(r375);

  BoundingRectangle* r376 = new BoundingRectangle(59, 61, 75,77);
  returnList.push_back(r376);

  BoundingRectangle* r377 = new BoundingRectangle(29, 29, 91,99);
  returnList.push_back(r377);

  BoundingRectangle* r378 = new BoundingRectangle(22, 27, 93,93);
  returnList.push_back(r378);

  BoundingRectangle* r379 = new BoundingRectangle(64, 65, 71,73);
  returnList.push_back(r379);

  BoundingRectangle* r380 = new BoundingRectangle(71, 71, 64,69);
  returnList.push_back(r380);

  BoundingRectangle* r381 = new BoundingRectangle(54, 60, 79,81);
  returnList.push_back(r381);

  BoundingRectangle* r382 = new BoundingRectangle(44, 46, 85,97);
  returnList.push_back(r382);

  BoundingRectangle* r383 = new BoundingRectangle(96, 96, 1,22);
  returnList.push_back(r383);

  BoundingRectangle* r384 = new BoundingRectangle(56, 60, 78,81);
  returnList.push_back(r384);

  BoundingRectangle* r385 = new BoundingRectangle(4, 8, 96,98);
  returnList.push_back(r385);

  BoundingRectangle* r386 = new BoundingRectangle(58, 60, 77,79);
  returnList.push_back(r386);

  BoundingRectangle* r387 = new BoundingRectangle(22, 24, 94,103);
  returnList.push_back(r387);

  BoundingRectangle* r388 = new BoundingRectangle(94, 96, 22,22);
  returnList.push_back(r388);

  BoundingRectangle* r389 = new BoundingRectangle(3, 8, 97,98);
  returnList.push_back(r389);

  BoundingRectangle* r390 = new BoundingRectangle(43, 50, 87,94);
  returnList.push_back(r390);

  BoundingRectangle* r391 = new BoundingRectangle(41, 41, 88,101);
  returnList.push_back(r391);

  BoundingRectangle* r392 = new BoundingRectangle(63, 63, 74,74);
  returnList.push_back(r392);

  BoundingRectangle* r393 = new BoundingRectangle(21, 27, 95,95);
  returnList.push_back(r393);

  BoundingRectangle* r394 = new BoundingRectangle(95, 96, 21,22);
  returnList.push_back(r394);

  BoundingRectangle* r395 = new BoundingRectangle(51, 51, 83,83);
  returnList.push_back(r395);

  BoundingRectangle* r396 = new BoundingRectangle(48, 50, 85,97);
  returnList.push_back(r396);

  BoundingRectangle* r397 = new BoundingRectangle(95, 95, 23,83);
  returnList.push_back(r397);

  BoundingRectangle* r398 = new BoundingRectangle(47, 51, 86,90);
  returnList.push_back(r398);

  BoundingRectangle* r399 = new BoundingRectangle(98, 100, 1,3);
  returnList.push_back(r399);

  BoundingRectangle* r400 = new BoundingRectangle(31, 32, 93,95);
  returnList.push_back(r400);

  BoundingRectangle* r401 = new BoundingRectangle(39, 41, 90,99);
  returnList.push_back(r401);

  BoundingRectangle* r402 = new BoundingRectangle(37, 37, 91,97);
  returnList.push_back(r402);

  BoundingRectangle* r403 = new BoundingRectangle(98, 100, 7,8);
  returnList.push_back(r403);

  BoundingRectangle* r404 = new BoundingRectangle(70, 71, 69,69);
  returnList.push_back(r404);

  BoundingRectangle* r405 = new BoundingRectangle(98, 100, 11,13);
  returnList.push_back(r405);

  BoundingRectangle* r406 = new BoundingRectangle(18, 20, 97,99);
  returnList.push_back(r406);

  BoundingRectangle* r407 = new BoundingRectangle(61, 61, 78,79);
  returnList.push_back(r407);

  BoundingRectangle* r408 = new BoundingRectangle(99, 100, 4,19);
  returnList.push_back(r408);

  BoundingRectangle* r409 = new BoundingRectangle(5, 5, 99,103);
  returnList.push_back(r409);

  BoundingRectangle* r410 = new BoundingRectangle(25, 27, 96,98);
  returnList.push_back(r410);

  BoundingRectangle* r411 = new BoundingRectangle(96, 96, 25,25);
  returnList.push_back(r411);

  BoundingRectangle* r412 = new BoundingRectangle(98, 100, 16,17);
  returnList.push_back(r412);

  BoundingRectangle* r413 = new BoundingRectangle(64, 64, 76,77);
  returnList.push_back(r413);

  BoundingRectangle* r414 = new BoundingRectangle(52, 52, 85,89);
  returnList.push_back(r414);

  BoundingRectangle* r415 = new BoundingRectangle(73, 82, 68,71);
  returnList.push_back(r415);

  BoundingRectangle* r416 = new BoundingRectangle(57, 59, 82,83);
  returnList.push_back(r416);

  BoundingRectangle* r417 = new BoundingRectangle(4, 7, 100,103);
  returnList.push_back(r417);

  BoundingRectangle* r418 = new BoundingRectangle(56, 59, 83,83);
  returnList.push_back(r418);

  BoundingRectangle* r419 = new BoundingRectangle(9, 9, 100,100);
  returnList.push_back(r419);

  BoundingRectangle* r420 = new BoundingRectangle(98, 100, 23,27);
  returnList.push_back(r420);

  BoundingRectangle* r421 = new BoundingRectangle(65, 65, 77,84);
  returnList.push_back(r421);

  BoundingRectangle* r422 = new BoundingRectangle(94, 95, 37,37);
  returnList.push_back(r422);

  BoundingRectangle* r423 = new BoundingRectangle(3, 7, 101,103);
  returnList.push_back(r423);

  BoundingRectangle* r424 = new BoundingRectangle(33, 35, 96,98);
  returnList.push_back(r424);

  BoundingRectangle* r425 = new BoundingRectangle(54, 56, 86,87);
  returnList.push_back(r425);

  BoundingRectangle* r426 = new BoundingRectangle(64, 65, 79,84);
  returnList.push_back(r426);

  BoundingRectangle* r427 = new BoundingRectangle(63, 65, 80,83);
  returnList.push_back(r427);

  BoundingRectangle* r428 = new BoundingRectangle(31, 35, 97,98);
  returnList.push_back(r428);

  BoundingRectangle* r429 = new BoundingRectangle(53, 56, 87,90);
  returnList.push_back(r429);

  BoundingRectangle* r430 = new BoundingRectangle(58, 59, 84,84);
  returnList.push_back(r430);

  BoundingRectangle* r431 = new BoundingRectangle(102, 104, 4,5);
  returnList.push_back(r431);

  BoundingRectangle* r432 = new BoundingRectangle(21, 24, 100,100);
  returnList.push_back(r432);

  BoundingRectangle* r433 = new BoundingRectangle(102, 104, 8,8);
  returnList.push_back(r433);

  BoundingRectangle* r434 = new BoundingRectangle(98, 100, 30,30);
  returnList.push_back(r434);

  BoundingRectangle* r435 = new BoundingRectangle(102, 104, 10,11);
  returnList.push_back(r435);

  BoundingRectangle* r436 = new BoundingRectangle(73, 78, 72,80);
  returnList.push_back(r436);

  BoundingRectangle* r437 = new BoundingRectangle(18, 20, 101,102);
  returnList.push_back(r437);

  BoundingRectangle* r438 = new BoundingRectangle(62, 62, 82,84);
  returnList.push_back(r438);

  BoundingRectangle* r439 = new BoundingRectangle(99, 100, 28,41);
  returnList.push_back(r439);

  BoundingRectangle* r440 = new BoundingRectangle(61, 62, 83,84);
  returnList.push_back(r440);

  BoundingRectangle* r441 = new BoundingRectangle(103, 104, 3,18);
  returnList.push_back(r441);

  BoundingRectangle* r442 = new BoundingRectangle(96, 96, 38,38);
  returnList.push_back(r442);

  BoundingRectangle* r443 = new BoundingRectangle(102, 108, 16,16);
  returnList.push_back(r443);

  BoundingRectangle* r444 = new BoundingRectangle(98, 100, 33,38);
  returnList.push_back(r444);

  BoundingRectangle* r445 = new BoundingRectangle(57, 59, 87,89);
  returnList.push_back(r445);

  BoundingRectangle* r446 = new BoundingRectangle(32, 32, 99,104);
  returnList.push_back(r446);

  BoundingRectangle* r447 = new BoundingRectangle(43, 44, 95,99);
  returnList.push_back(r447);

  BoundingRectangle* r448 = new BoundingRectangle(59, 59, 86,104);
  returnList.push_back(r448);

  BoundingRectangle* r449 = new BoundingRectangle(51, 51, 91,92);
  returnList.push_back(r449);

  BoundingRectangle* r450 = new BoundingRectangle(31, 32, 100,104);
  returnList.push_back(r450);

  BoundingRectangle* r451 = new BoundingRectangle(103, 103, 19,19);
  returnList.push_back(r451);

  BoundingRectangle* r452 = new BoundingRectangle(68, 68, 80,80);
  returnList.push_back(r452);

  BoundingRectangle* r453 = new BoundingRectangle(25, 27, 102,103);
  returnList.push_back(r453);

  BoundingRectangle* r454 = new BoundingRectangle(3, 9, 105,123);
  returnList.push_back(r454);

  BoundingRectangle* r455 = new BoundingRectangle(105, 108, 5,7);
  returnList.push_back(r455);

  BoundingRectangle* r456 = new BoundingRectangle(53, 55, 91,99);
  returnList.push_back(r456);

  BoundingRectangle* r457 = new BoundingRectangle(60, 64, 87,89);
  returnList.push_back(r457);

  BoundingRectangle* r458 = new BoundingRectangle(105, 108, 12,13);
  returnList.push_back(r458);

  BoundingRectangle* r459 = new BoundingRectangle(42, 50, 97,97);
  returnList.push_back(r459);

  BoundingRectangle* r460 = new BoundingRectangle(47, 50, 95,97);
  returnList.push_back(r460);

  BoundingRectangle* r461 = new BoundingRectangle(62, 63, 86,89);
  returnList.push_back(r461);

  BoundingRectangle* r462 = new BoundingRectangle(106, 108, 4,20);
  returnList.push_back(r462);

  BoundingRectangle* r463 = new BoundingRectangle(33, 35, 101,102);
  returnList.push_back(r463);

  BoundingRectangle* r464 = new BoundingRectangle(105, 108, 17,17);
  returnList.push_back(r464);

  BoundingRectangle* r465 = new BoundingRectangle(18, 18, 105,122);
  returnList.push_back(r465);

  BoundingRectangle* r466 = new BoundingRectangle(57, 59, 90,90);
  returnList.push_back(r466);

  BoundingRectangle* r467 = new BoundingRectangle(98, 99, 42,46);
  returnList.push_back(r467);

  BoundingRectangle* r468 = new BoundingRectangle(13, 13, 106,116);
  returnList.push_back(r468);

  BoundingRectangle* r469 = new BoundingRectangle(79, 82, 73,80);
  returnList.push_back(r469);

  BoundingRectangle* r470 = new BoundingRectangle(80, 82, 72,80);
  returnList.push_back(r470);

  BoundingRectangle* r471 = new BoundingRectangle(19, 23, 106,122);
  returnList.push_back(r471);

  BoundingRectangle* r472 = new BoundingRectangle(40, 41, 100,101);
  returnList.push_back(r472);

  BoundingRectangle* r473 = new BoundingRectangle(65, 66, 86,86);
  returnList.push_back(r473);

  BoundingRectangle* r474 = new BoundingRectangle(58, 61, 91,94);
  returnList.push_back(r474);

  BoundingRectangle* r475 = new BoundingRectangle(1, 9, 108,121);
  returnList.push_back(r475);

  BoundingRectangle* r476 = new BoundingRectangle(106, 107, 21,21);
  returnList.push_back(r476);

  BoundingRectangle* r477 = new BoundingRectangle(105, 115, 26,36);
  returnList.push_back(r477);

  BoundingRectangle* r478 = new BoundingRectangle(57, 61, 92,100);
  returnList.push_back(r478);

  BoundingRectangle* r479 = new BoundingRectangle(46, 48, 98,102);
  returnList.push_back(r479);

  BoundingRectangle* r480 = new BoundingRectangle(91, 91, 59,84);
  returnList.push_back(r480);

  BoundingRectangle* r481 = new BoundingRectangle(61, 61, 90,101);
  returnList.push_back(r481);

  BoundingRectangle* r482 = new BoundingRectangle(45, 50, 99,99);
  returnList.push_back(r482);

  BoundingRectangle* r483 = new BoundingRectangle(100, 100, 43,58);
  returnList.push_back(r483);

  BoundingRectangle* r484 = new BoundingRectangle(14, 15, 108,109);
  returnList.push_back(r484);

  BoundingRectangle* r485 = new BoundingRectangle(25, 25, 106,123);
  returnList.push_back(r485);

  BoundingRectangle* r486 = new BoundingRectangle(73, 76, 81,84);
  returnList.push_back(r486);

  BoundingRectangle* r487 = new BoundingRectangle(98, 100, 48,48);
  returnList.push_back(r487);

  BoundingRectangle* r488 = new BoundingRectangle(65, 65, 88,88);
  returnList.push_back(r488);

  BoundingRectangle* r489 = new BoundingRectangle(99, 100, 47,54);
  returnList.push_back(r489);

  BoundingRectangle* r490 = new BoundingRectangle(68, 69, 86,86);
  returnList.push_back(r490);

  BoundingRectangle* r491 = new BoundingRectangle(24, 25, 107,113);
  returnList.push_back(r491);

  BoundingRectangle* r492 = new BoundingRectangle(107, 107, 24,34);
  returnList.push_back(r492);

  BoundingRectangle* r493 = new BoundingRectangle(43, 43, 101,104);
  returnList.push_back(r493);

  BoundingRectangle* r494 = new BoundingRectangle(67, 67, 87,87);
  returnList.push_back(r494);

  BoundingRectangle* r495 = new BoundingRectangle(92, 93, 60,60);
  returnList.push_back(r495);

  BoundingRectangle* r496 = new BoundingRectangle(63, 71, 90,91);
  returnList.push_back(r496);

  BoundingRectangle* r497 = new BoundingRectangle(66, 66, 88,88);
  returnList.push_back(r497);

  BoundingRectangle* r498 = new BoundingRectangle(50, 50, 98,104);
  returnList.push_back(r498);

  BoundingRectangle* r499 = new BoundingRectangle(98, 100, 50,50);
  returnList.push_back(r499);

  BoundingRectangle* r500 = new BoundingRectangle(62, 66, 91,94);
  returnList.push_back(r500);

  BoundingRectangle* r501 = new BoundingRectangle(93, 93, 59,78);
  returnList.push_back(r501);

  BoundingRectangle* r502 = new BoundingRectangle(44, 48, 101,102);
  returnList.push_back(r502);

  BoundingRectangle* r503 = new BoundingRectangle(65, 65, 89,104);
  returnList.push_back(r503);

  BoundingRectangle* r504 = new BoundingRectangle(27, 30, 107,116);
  returnList.push_back(r504);

  BoundingRectangle* r505 = new BoundingRectangle(90, 93, 64,64);
  returnList.push_back(r505);

  BoundingRectangle* r506 = new BoundingRectangle(108, 117, 24,30);
  returnList.push_back(r506);

  BoundingRectangle* r507 = new BoundingRectangle(98, 100, 52,52);
  returnList.push_back(r507);

  BoundingRectangle* r508 = new BoundingRectangle(69, 69, 87,105);
  returnList.push_back(r508);

  BoundingRectangle* r509 = new BoundingRectangle(102, 104, 44,46);
  returnList.push_back(r509);

  BoundingRectangle* r510 = new BoundingRectangle(68, 71, 88,91);
  returnList.push_back(r510);

  BoundingRectangle* r511 = new BoundingRectangle(34, 35, 106,124);
  returnList.push_back(r511);

  BoundingRectangle* r512 = new BoundingRectangle(105, 115, 37,38);
  returnList.push_back(r512);

  BoundingRectangle* r513 = new BoundingRectangle(109, 117, 23,35);
  returnList.push_back(r513);

  BoundingRectangle* r514 = new BoundingRectangle(92, 93, 63,77);
  returnList.push_back(r514);

  BoundingRectangle* r515 = new BoundingRectangle(71, 71, 86,86);
  returnList.push_back(r515);

  BoundingRectangle* r516 = new BoundingRectangle(14, 15, 111,116);
  returnList.push_back(r516);

  BoundingRectangle* r517 = new BoundingRectangle(98, 100, 54,54);
  returnList.push_back(r517);

  BoundingRectangle* r518 = new BoundingRectangle(97, 100, 56,56);
  returnList.push_back(r518);

  BoundingRectangle* r519 = new BoundingRectangle(112, 119, 5,9);
  returnList.push_back(r519);

  BoundingRectangle* r520 = new BoundingRectangle(72, 72, 86,86);
  returnList.push_back(r520);

  BoundingRectangle* r521 = new BoundingRectangle(71, 71, 87,105);
  returnList.push_back(r521);

  BoundingRectangle* r522 = new BoundingRectangle(102, 104, 47,47);
  returnList.push_back(r522);

  BoundingRectangle* r523 = new BoundingRectangle(45, 45, 103,104);
  returnList.push_back(r523);

  BoundingRectangle* r524 = new BoundingRectangle(112, 113, 10,17);
  returnList.push_back(r524);

  BoundingRectangle* r525 = new BoundingRectangle(78, 81, 81,81);
  returnList.push_back(r525);

  BoundingRectangle* r526 = new BoundingRectangle(77, 77, 82,82);
  returnList.push_back(r526);

  BoundingRectangle* r527 = new BoundingRectangle(83, 83, 76,76);
  returnList.push_back(r527);

  BoundingRectangle* r528 = new BoundingRectangle(44, 50, 104,104);
  returnList.push_back(r528);

  BoundingRectangle* r529 = new BoundingRectangle(39, 40, 106,111);
  returnList.push_back(r529);

  BoundingRectangle* r530 = new BoundingRectangle(102, 106, 49,51);
  returnList.push_back(r530);

  BoundingRectangle* r531 = new BoundingRectangle(53, 54, 100,102);
  returnList.push_back(r531);

  BoundingRectangle* r532 = new BoundingRectangle(98, 99, 57,58);
  returnList.push_back(r532);

  BoundingRectangle* r533 = new BoundingRectangle(73, 104, 87,88);
  returnList.push_back(r533);

  BoundingRectangle* r534 = new BoundingRectangle(103, 106, 48,52);
  returnList.push_back(r534);

  BoundingRectangle* r535 = new BoundingRectangle(72, 127, 88,88);
  returnList.push_back(r535);

  BoundingRectangle* r536 = new BoundingRectangle(105, 118, 44,46);
  returnList.push_back(r536);

  BoundingRectangle* r537 = new BoundingRectangle(107, 107, 39,42);
  returnList.push_back(r537);

  BoundingRectangle* r538 = new BoundingRectangle(77, 78, 84,84);
  returnList.push_back(r538);

  BoundingRectangle* r539 = new BoundingRectangle(63, 71, 95,104);
  returnList.push_back(r539);

  BoundingRectangle* r540 = new BoundingRectangle(90, 93, 70,70);
  returnList.push_back(r540);

  BoundingRectangle* r541 = new BoundingRectangle(114, 119, 2,9);
  returnList.push_back(r541);

  BoundingRectangle* r542 = new BoundingRectangle(97, 100, 60,61);
  returnList.push_back(r542);

  BoundingRectangle* r543 = new BoundingRectangle(49, 50, 103,104);
  returnList.push_back(r543);

  BoundingRectangle* r544 = new BoundingRectangle(75, 83, 86,94);
  returnList.push_back(r544);

  BoundingRectangle* r545 = new BoundingRectangle(86, 86, 75,84);
  returnList.push_back(r545);

  BoundingRectangle* r546 = new BoundingRectangle(62, 71, 96,104);
  returnList.push_back(r546);

  BoundingRectangle* r547 = new BoundingRectangle(98, 99, 59,85);
  returnList.push_back(r547);

  BoundingRectangle* r548 = new BoundingRectangle(68, 71, 92,104);
  returnList.push_back(r548);

  BoundingRectangle* r549 = new BoundingRectangle(80, 81, 82,84);
  returnList.push_back(r549);

  BoundingRectangle* r550 = new BoundingRectangle(67, 71, 93,104);
  returnList.push_back(r550);

  BoundingRectangle* r551 = new BoundingRectangle(114, 122, 12,20);
  returnList.push_back(r551);

  BoundingRectangle* r552 = new BoundingRectangle(108, 115, 39,41);
  returnList.push_back(r552);

  BoundingRectangle* r553 = new BoundingRectangle(102, 102, 53,60);
  returnList.push_back(r553);

  BoundingRectangle* r554 = new BoundingRectangle(55, 55, 101,104);
  returnList.push_back(r554);

  BoundingRectangle* r555 = new BoundingRectangle(115, 122, 10,20);
  returnList.push_back(r555);

  BoundingRectangle* r556 = new BoundingRectangle(41, 43, 108,110);
  returnList.push_back(r556);

  BoundingRectangle* r557 = new BoundingRectangle(74, 82, 89,97);
  returnList.push_back(r557);

  BoundingRectangle* r558 = new BoundingRectangle(53, 53, 103,104);
  returnList.push_back(r558);

  BoundingRectangle* r559 = new BoundingRectangle(106, 110, 47,49);
  returnList.push_back(r559);

  BoundingRectangle* r560 = new BoundingRectangle(116, 119, 1,4);
  returnList.push_back(r560);

  BoundingRectangle* r561 = new BoundingRectangle(103, 107, 54,58);
  returnList.push_back(r561);

  BoundingRectangle* r562 = new BoundingRectangle(58, 59, 101,102);
  returnList.push_back(r562);

  BoundingRectangle* r563 = new BoundingRectangle(73, 82, 91,100);
  returnList.push_back(r563);

  BoundingRectangle* r564 = new BoundingRectangle(104, 108, 53,57);
  returnList.push_back(r564);

  BoundingRectangle* r565 = new BoundingRectangle(109, 110, 42,42);
  returnList.push_back(r565);

  BoundingRectangle* r566 = new BoundingRectangle(57, 57, 102,102);
  returnList.push_back(r566);

  BoundingRectangle* r567 = new BoundingRectangle(37, 37, 111,115);
  returnList.push_back(r567);

  BoundingRectangle* r568 = new BoundingRectangle(115, 117, 22,35);
  returnList.push_back(r568);

  BoundingRectangle* r569 = new BoundingRectangle(54, 55, 104,104);
  returnList.push_back(r569);

  BoundingRectangle* r570 = new BoundingRectangle(32, 32, 113,115);
  returnList.push_back(r570);

  BoundingRectangle* r571 = new BoundingRectangle(24, 25, 115,123);
  returnList.push_back(r571);

  BoundingRectangle* r572 = new BoundingRectangle(60, 71, 101,101);
  returnList.push_back(r572);

  BoundingRectangle* r573 = new BoundingRectangle(44, 45, 109,122);
  returnList.push_back(r573);

  BoundingRectangle* r574 = new BoundingRectangle(100, 100, 62,69);
  returnList.push_back(r574);

  BoundingRectangle* r575 = new BoundingRectangle(57, 57, 103,105);
  returnList.push_back(r575);

  BoundingRectangle* r576 = new BoundingRectangle(90, 91, 76,77);
  returnList.push_back(r576);

  BoundingRectangle* r577 = new BoundingRectangle(97, 100, 68,68);
  returnList.push_back(r577);

  BoundingRectangle* r578 = new BoundingRectangle(107, 111, 51,55);
  returnList.push_back(r578);

  BoundingRectangle* r579 = new BoundingRectangle(42, 45, 111,122);
  returnList.push_back(r579);

  BoundingRectangle* r580 = new BoundingRectangle(103, 107, 59,60);
  returnList.push_back(r580);

  BoundingRectangle* r581 = new BoundingRectangle(108, 115, 50,55);
  returnList.push_back(r581);

  BoundingRectangle* r582 = new BoundingRectangle(90, 91, 78,84);
  returnList.push_back(r582);

  BoundingRectangle* r583 = new BoundingRectangle(60, 60, 103,105);
  returnList.push_back(r583);

  BoundingRectangle* r584 = new BoundingRectangle(102, 113, 62,63);
  returnList.push_back(r584);

  BoundingRectangle* r585 = new BoundingRectangle(51, 57, 108,116);
  returnList.push_back(r585);

  BoundingRectangle* r586 = new BoundingRectangle(39, 40, 113,119);
  returnList.push_back(r586);

  BoundingRectangle* r587 = new BoundingRectangle(112, 115, 42,42);
  returnList.push_back(r587);

  BoundingRectangle* r588 = new BoundingRectangle(61, 71, 103,104);
  returnList.push_back(r588);

  BoundingRectangle* r589 = new BoundingRectangle(54, 54, 107,125);
  returnList.push_back(r589);

  BoundingRectangle* r590 = new BoundingRectangle(120, 122, 1,3);
  returnList.push_back(r590);

  BoundingRectangle* r591 = new BoundingRectangle(120, 122, 4,4);
  returnList.push_back(r591);

  BoundingRectangle* r592 = new BoundingRectangle(27, 29, 117,124);
  returnList.push_back(r592);

  BoundingRectangle* r593 = new BoundingRectangle(120, 122, 6,20);
  returnList.push_back(r593);

  BoundingRectangle* r594 = new BoundingRectangle(84, 84, 86,90);
  returnList.push_back(r594);

  BoundingRectangle* r595 = new BoundingRectangle(118, 119, 24,25);
  returnList.push_back(r595);

  BoundingRectangle* r596 = new BoundingRectangle(49, 55, 110,116);
  returnList.push_back(r596);

  BoundingRectangle* r597 = new BoundingRectangle(104, 104, 61,63);
  returnList.push_back(r597);

  BoundingRectangle* r598 = new BoundingRectangle(13, 13, 120,124);
  returnList.push_back(r598);

  BoundingRectangle* r599 = new BoundingRectangle(56, 57, 107,108);
  returnList.push_back(r599);

  BoundingRectangle* r600 = new BoundingRectangle(97, 99, 72,74);
  returnList.push_back(r600);

  BoundingRectangle* r601 = new BoundingRectangle(118, 118, 26,27);
  returnList.push_back(r601);

  BoundingRectangle* r602 = new BoundingRectangle(111, 115, 48,52);
  returnList.push_back(r602);

  BoundingRectangle* r603 = new BoundingRectangle(102, 105, 65,81);
  returnList.push_back(r603);

  BoundingRectangle* r604 = new BoundingRectangle(119, 122, 22,25);
  returnList.push_back(r604);

  BoundingRectangle* r605 = new BoundingRectangle(121, 122, 5,20);
  returnList.push_back(r605);

  BoundingRectangle* r606 = new BoundingRectangle(41, 45, 114,115);
  returnList.push_back(r606);

  BoundingRectangle* r607 = new BoundingRectangle(32, 32, 117,120);
  returnList.push_back(r607);

  BoundingRectangle* r608 = new BoundingRectangle(112, 113, 47,48);
  returnList.push_back(r608);

  BoundingRectangle* r609 = new BoundingRectangle(94, 95, 77,83);
  returnList.push_back(r609);

  BoundingRectangle* r610 = new BoundingRectangle(118, 119, 29,30);
  returnList.push_back(r610);

  BoundingRectangle* r611 = new BoundingRectangle(86, 92, 86,105);
  returnList.push_back(r611);

  BoundingRectangle* r612 = new BoundingRectangle(58, 61, 107,108);
  returnList.push_back(r612);

  BoundingRectangle* r613 = new BoundingRectangle(14, 15, 121,124);
  returnList.push_back(r613);

  BoundingRectangle* r614 = new BoundingRectangle(62, 63, 105,105);
  returnList.push_back(r614);

  BoundingRectangle* r615 = new BoundingRectangle(118, 118, 31,37);
  returnList.push_back(r615);

  BoundingRectangle* r616 = new BoundingRectangle(119, 119, 27,30);
  returnList.push_back(r616);

  BoundingRectangle* r617 = new BoundingRectangle(109, 110, 56,57);
  returnList.push_back(r617);

  BoundingRectangle* r618 = new BoundingRectangle(30, 30, 119,119);
  returnList.push_back(r618);

  BoundingRectangle* r619 = new BoundingRectangle(120, 127, 27,29);
  returnList.push_back(r619);

  BoundingRectangle* r620 = new BoundingRectangle(123, 123, 1,3);
  returnList.push_back(r620);

  BoundingRectangle* r621 = new BoundingRectangle(85, 103, 89,105);
  returnList.push_back(r621);

  BoundingRectangle* r622 = new BoundingRectangle(107, 113, 61,63);
  returnList.push_back(r622);

  BoundingRectangle* r623 = new BoundingRectangle(119, 119, 32,35);
  returnList.push_back(r623);

  BoundingRectangle* r624 = new BoundingRectangle(114, 122, 47,48);
  returnList.push_back(r624);

  BoundingRectangle* r625 = new BoundingRectangle(117, 127, 39,40);
  returnList.push_back(r625);

  BoundingRectangle* r626 = new BoundingRectangle(108, 113, 60,63);
  returnList.push_back(r626);

  BoundingRectangle* r627 = new BoundingRectangle(37, 37, 118,120);
  returnList.push_back(r627);

  BoundingRectangle* r628 = new BoundingRectangle(121, 126, 26,35);
  returnList.push_back(r628);

  BoundingRectangle* r629 = new BoundingRectangle(124, 127, 2,20);
  returnList.push_back(r629);

  BoundingRectangle* r630 = new BoundingRectangle(66, 66, 105,105);
  returnList.push_back(r630);

  BoundingRectangle* r631 = new BoundingRectangle(4, 4, 124,124);
  returnList.push_back(r631);

  BoundingRectangle* r632 = new BoundingRectangle(6, 9, 124,124);
  returnList.push_back(r632);

  BoundingRectangle* r633 = new BoundingRectangle(120, 127, 32,34);
  returnList.push_back(r633);

  BoundingRectangle* r634 = new BoundingRectangle(58, 58, 110,111);
  returnList.push_back(r634);

  BoundingRectangle* r635 = new BoundingRectangle(110, 113, 58,61);
  returnList.push_back(r635);

  BoundingRectangle* r636 = new BoundingRectangle(100, 100, 74,74);
  returnList.push_back(r636);

  BoundingRectangle* r637 = new BoundingRectangle(60, 64, 109,113);
  returnList.push_back(r637);

  BoundingRectangle* r638 = new BoundingRectangle(62, 63, 108,113);
  returnList.push_back(r638);

  BoundingRectangle* r639 = new BoundingRectangle(73, 82, 101,105);
  returnList.push_back(r639);

  BoundingRectangle* r640 = new BoundingRectangle(119, 119, 37,42);
  returnList.push_back(r640);

  BoundingRectangle* r641 = new BoundingRectangle(64, 72, 107,107);
  returnList.push_back(r641);

  BoundingRectangle* r642 = new BoundingRectangle(106, 116, 66,76);
  returnList.push_back(r642);

  BoundingRectangle* r643 = new BoundingRectangle(118, 119, 41,42);
  returnList.push_back(r643);

  BoundingRectangle* r644 = new BoundingRectangle(22, 25, 123,123);
  returnList.push_back(r644);

  BoundingRectangle* r645 = new BoundingRectangle(68, 69, 105,105);
  returnList.push_back(r645);

  BoundingRectangle* r646 = new BoundingRectangle(123, 127, 23,25);
  returnList.push_back(r646);

  BoundingRectangle* r647 = new BoundingRectangle(107, 107, 65,84);
  returnList.push_back(r647);

  BoundingRectangle* r648 = new BoundingRectangle(120, 127, 37,41);
  returnList.push_back(r648);

  BoundingRectangle* r649 = new BoundingRectangle(59, 71, 111,123);
  returnList.push_back(r649);

  BoundingRectangle* r650 = new BoundingRectangle(97, 99, 80,81);
  returnList.push_back(r650);

  BoundingRectangle* r651 = new BoundingRectangle(41, 45, 119,120);
  returnList.push_back(r651);

  BoundingRectangle* r652 = new BoundingRectangle(116, 127, 49,49);
  returnList.push_back(r652);

  BoundingRectangle* r653 = new BoundingRectangle(124, 124, 22,42);
  returnList.push_back(r653);

  BoundingRectangle* r654 = new BoundingRectangle(126, 127, 1,21);
  returnList.push_back(r654);

  BoundingRectangle* r655 = new BoundingRectangle(65, 67, 108,108);
  returnList.push_back(r655);

  BoundingRectangle* r656 = new BoundingRectangle(94, 94, 84,85);
  returnList.push_back(r656);

  BoundingRectangle* r657 = new BoundingRectangle(113, 116, 56,61);
  returnList.push_back(r657);

  BoundingRectangle* r658 = new BoundingRectangle(83, 83, 95,97);
  returnList.push_back(r658);

  BoundingRectangle* r659 = new BoundingRectangle(121, 121, 36,42);
  returnList.push_back(r659);

  BoundingRectangle* r660 = new BoundingRectangle(116, 116, 51,52);
  returnList.push_back(r660);

  BoundingRectangle* r661 = new BoundingRectangle(49, 50, 117,121);
  returnList.push_back(r661);

  BoundingRectangle* r662 = new BoundingRectangle(109, 118, 65,66);
  returnList.push_back(r662);

  BoundingRectangle* r663 = new BoundingRectangle(47, 47, 118,120);
  returnList.push_back(r663);

  BoundingRectangle* r664 = new BoundingRectangle(58, 62, 113,117);
  returnList.push_back(r664);

  BoundingRectangle* r665 = new BoundingRectangle(39, 40, 121,125);
  returnList.push_back(r665);

  BoundingRectangle* r666 = new BoundingRectangle(119, 124, 45,46);
  returnList.push_back(r666);

  BoundingRectangle* r667 = new BoundingRectangle(117, 127, 50,50);
  returnList.push_back(r667);

  BoundingRectangle* r668 = new BoundingRectangle(66, 71, 109,114);
  returnList.push_back(r668);

  BoundingRectangle* r669 = new BoundingRectangle(120, 122, 44,46);
  returnList.push_back(r669);

  BoundingRectangle* r670 = new BoundingRectangle(116, 116, 54,63);
  returnList.push_back(r670);

  BoundingRectangle* r671 = new BoundingRectangle(69, 70, 108,109);
  returnList.push_back(r671);

  BoundingRectangle* r672 = new BoundingRectangle(123, 127, 36,41);
  returnList.push_back(r672);

  BoundingRectangle* r673 = new BoundingRectangle(53, 55, 117,125);
  returnList.push_back(r673);

  BoundingRectangle* r674 = new BoundingRectangle(51, 51, 118,119);
  returnList.push_back(r674);

  BoundingRectangle* r675 = new BoundingRectangle(96, 97, 86,105);
  returnList.push_back(r675);

  BoundingRectangle* r676 = new BoundingRectangle(122, 122, 42,42);
  returnList.push_back(r676);

  BoundingRectangle* r677 = new BoundingRectangle(71, 110, 108,109);
  returnList.push_back(r677);

  BoundingRectangle* r678 = new BoundingRectangle(119, 127, 51,54);
  returnList.push_back(r678);

  BoundingRectangle* r679 = new BoundingRectangle(35, 35, 125,125);
  returnList.push_back(r679);

  BoundingRectangle* r680 = new BoundingRectangle(52, 60, 119,119);
  returnList.push_back(r680);

  BoundingRectangle* r681 = new BoundingRectangle(42, 43, 123,123);
  returnList.push_back(r681);

  BoundingRectangle* r682 = new BoundingRectangle(74, 81, 107,114);
  returnList.push_back(r682);

  BoundingRectangle* r683 = new BoundingRectangle(57, 57, 117,117);
  returnList.push_back(r683);

  BoundingRectangle* r684 = new BoundingRectangle(114, 116, 63,63);
  returnList.push_back(r684);

  BoundingRectangle* r685 = new BoundingRectangle(127, 127, 30,42);
  returnList.push_back(r685);

  BoundingRectangle* r686 = new BoundingRectangle(100, 100, 84,85);
  returnList.push_back(r686);

  BoundingRectangle* r687 = new BoundingRectangle(56, 57, 118,125);
  returnList.push_back(r687);

  BoundingRectangle* r688 = new BoundingRectangle(123, 124, 44,46);
  returnList.push_back(r688);

  BoundingRectangle* r689 = new BoundingRectangle(115, 116, 62,63);
  returnList.push_back(r689);

  BoundingRectangle* r690 = new BoundingRectangle(102, 103, 82,85);
  returnList.push_back(r690);

  BoundingRectangle* r691 = new BoundingRectangle(106, 111, 77,78);
  returnList.push_back(r691);

  BoundingRectangle* r692 = new BoundingRectangle(119, 124, 55,60);
  returnList.push_back(r692);

  BoundingRectangle* r693 = new BoundingRectangle(99, 99, 86,105);
  returnList.push_back(r693);

  BoundingRectangle* r694 = new BoundingRectangle(51, 60, 121,125);
  returnList.push_back(r694);

  BoundingRectangle* r695 = new BoundingRectangle(72, 81, 110,114);
  returnList.push_back(r695);

  BoundingRectangle* r696 = new BoundingRectangle(125, 127, 42,42);
  returnList.push_back(r696);

  BoundingRectangle* r697 = new BoundingRectangle(123, 127, 48,54);
  returnList.push_back(r697);

  BoundingRectangle* r698 = new BoundingRectangle(106, 108, 79,84);
  returnList.push_back(r698);

  BoundingRectangle* r699 = new BoundingRectangle(125, 127, 44,44);
  returnList.push_back(r699);

  BoundingRectangle* r700 = new BoundingRectangle(124, 127, 47,54);
  returnList.push_back(r700);

  BoundingRectangle* r701 = new BoundingRectangle(104, 116, 83,84);
  returnList.push_back(r701);

  BoundingRectangle* r702 = new BoundingRectangle(125, 127, 46,54);
  returnList.push_back(r702);

  BoundingRectangle* r703 = new BoundingRectangle(105, 108, 82,84);
  returnList.push_back(r703);

  BoundingRectangle* r704 = new BoundingRectangle(58, 60, 120,122);
  returnList.push_back(r704);

  BoundingRectangle* r705 = new BoundingRectangle(126, 127, 45,57);
  returnList.push_back(r705);

  BoundingRectangle* r706 = new BoundingRectangle(83, 83, 105,105);
  returnList.push_back(r706);

  BoundingRectangle* r707 = new BoundingRectangle(119, 122, 62,63);
  returnList.push_back(r707);

  BoundingRectangle* r708 = new BoundingRectangle(120, 122, 61,63);
  returnList.push_back(r708);

  BoundingRectangle* r709 = new BoundingRectangle(82, 82, 107,113);
  returnList.push_back(r709);

  BoundingRectangle* r710 = new BoundingRectangle(117, 118, 67,68);
  returnList.push_back(r710);

  BoundingRectangle* r711 = new BoundingRectangle(105, 106, 85,85);
  returnList.push_back(r711);

  BoundingRectangle* r712 = new BoundingRectangle(109, 116, 80,81);
  returnList.push_back(r712);

  BoundingRectangle* r713 = new BoundingRectangle(117, 117, 69,73);
  returnList.push_back(r713);

  BoundingRectangle* r714 = new BoundingRectangle(73, 81, 115,126);
  returnList.push_back(r714);

  BoundingRectangle* r715 = new BoundingRectangle(111, 116, 79,84);
  returnList.push_back(r715);

  BoundingRectangle* r716 = new BoundingRectangle(120, 120, 65,85);
  returnList.push_back(r716);

  BoundingRectangle* r717 = new BoundingRectangle(112, 116, 78,84);
  returnList.push_back(r717);

  BoundingRectangle* r718 = new BoundingRectangle(119, 125, 67,68);
  returnList.push_back(r718);

  BoundingRectangle* r719 = new BoundingRectangle(85, 97, 107,121);
  returnList.push_back(r719);

  BoundingRectangle* r720 = new BoundingRectangle(113, 116, 77,84);
  returnList.push_back(r720);

  BoundingRectangle* r721 = new BoundingRectangle(104, 110, 89,98);
  returnList.push_back(r721);

  BoundingRectangle* r722 = new BoundingRectangle(125, 126, 56,57);
  returnList.push_back(r722);

  BoundingRectangle* r723 = new BoundingRectangle(118, 123, 70,73);
  returnList.push_back(r723);

  BoundingRectangle* r724 = new BoundingRectangle(123, 124, 61,61);
  returnList.push_back(r724);

  BoundingRectangle* r725 = new BoundingRectangle(108, 109, 85,85);
  returnList.push_back(r725);

  BoundingRectangle* r726 = new BoundingRectangle(83, 95, 110,122);
  returnList.push_back(r726);

  BoundingRectangle* r727 = new BoundingRectangle(125, 126, 58,60);
  returnList.push_back(r727);

  BoundingRectangle* r728 = new BoundingRectangle(121, 123, 66,85);
  returnList.push_back(r728);

  BoundingRectangle* r729 = new BoundingRectangle(107, 110, 87,90);
  returnList.push_back(r729);

  BoundingRectangle* r730 = new BoundingRectangle(123, 126, 63,63);
  returnList.push_back(r730);

  BoundingRectangle* r731 = new BoundingRectangle(122, 123, 65,85);
  returnList.push_back(r731);

  BoundingRectangle* r732 = new BoundingRectangle(62, 70, 124,124);
  returnList.push_back(r732);

  BoundingRectangle* r733 = new BoundingRectangle(125, 126, 62,63);
  returnList.push_back(r733);

  BoundingRectangle* r734 = new BoundingRectangle(124, 124, 64,64);
  returnList.push_back(r734);

  BoundingRectangle* r735 = new BoundingRectangle(111, 112, 85,85);
  returnList.push_back(r735);

  BoundingRectangle* r736 = new BoundingRectangle(63, 70, 125,125);
  returnList.push_back(r736);

  BoundingRectangle* r737 = new BoundingRectangle(126, 126, 61,61);
  returnList.push_back(r737);

  BoundingRectangle* r738 = new BoundingRectangle(127, 127, 59,61);
  returnList.push_back(r738);

  BoundingRectangle* r739 = new BoundingRectangle(119, 123, 74,81);
  returnList.push_back(r739);

  BoundingRectangle* r740 = new BoundingRectangle(118, 127, 76,76);
  returnList.push_back(r740);

  BoundingRectangle* r741 = new BoundingRectangle(125, 125, 65,85);
  returnList.push_back(r741);

  BoundingRectangle* r742 = new BoundingRectangle(111, 115, 87,90);
  returnList.push_back(r742);

  BoundingRectangle* r743 = new BoundingRectangle(124, 127, 69,70);
  returnList.push_back(r743);

  BoundingRectangle* r744 = new BoundingRectangle(118, 127, 79,81);
  returnList.push_back(r744);

  BoundingRectangle* r745 = new BoundingRectangle(114, 114, 85,85);
  returnList.push_back(r745);

  BoundingRectangle* r746 = new BoundingRectangle(127, 127, 64,64);
  returnList.push_back(r746);

  BoundingRectangle* r747 = new BoundingRectangle(126, 127, 66,67);
  returnList.push_back(r747);

  BoundingRectangle* r748 = new BoundingRectangle(124, 126, 72,74);
  returnList.push_back(r748);

  BoundingRectangle* r749 = new BoundingRectangle(116, 116, 85,85);
  returnList.push_back(r749);

  BoundingRectangle* r750 = new BoundingRectangle(127, 127, 68,71);
  returnList.push_back(r750);

  BoundingRectangle* r751 = new BoundingRectangle(111, 127, 92,94);
  returnList.push_back(r751);

  BoundingRectangle* r752 = new BoundingRectangle(112, 127, 91,94);
  returnList.push_back(r752);

  BoundingRectangle* r753 = new BoundingRectangle(105, 110, 99,105);
  returnList.push_back(r753);

  BoundingRectangle* r754 = new BoundingRectangle(126, 126, 71,71);
  returnList.push_back(r754);

  BoundingRectangle* r755 = new BoundingRectangle(118, 127, 84,85);
  returnList.push_back(r755);

  BoundingRectangle* r756 = new BoundingRectangle(119, 127, 83,85);
  returnList.push_back(r756);

  BoundingRectangle* r757 = new BoundingRectangle(117, 126, 87,97);
  returnList.push_back(r757);

  BoundingRectangle* r758 = new BoundingRectangle(124, 127, 77,85);
  returnList.push_back(r758);

  BoundingRectangle* r759 = new BoundingRectangle(116, 127, 89,97);
  returnList.push_back(r759);

  BoundingRectangle* r760 = new BoundingRectangle(100, 107, 107,126);
  returnList.push_back(r760);

  BoundingRectangle* r761 = new BoundingRectangle(127, 127, 73,85);
  returnList.push_back(r761);

  BoundingRectangle* r762 = new BoundingRectangle(126, 127, 75,85);
  returnList.push_back(r762);

  BoundingRectangle* r763 = new BoundingRectangle(111, 113, 96,102);
  returnList.push_back(r763);

  BoundingRectangle* r764 = new BoundingRectangle(98, 109, 110,121);
  returnList.push_back(r764);

  BoundingRectangle* r765 = new BoundingRectangle(113, 113, 95,106);
  returnList.push_back(r765);

  BoundingRectangle* r766 = new BoundingRectangle(83, 95, 123,126);
  returnList.push_back(r766);

  BoundingRectangle* r767 = new BoundingRectangle(114, 119, 95,100);
  returnList.push_back(r767);

  BoundingRectangle* r768 = new BoundingRectangle(106, 113, 106,106);
  returnList.push_back(r768);

  BoundingRectangle* r769 = new BoundingRectangle(111, 113, 104,106);
  returnList.push_back(r769);

  BoundingRectangle* r770 = new BoundingRectangle(114, 119, 101,101);
  returnList.push_back(r770);

  BoundingRectangle* r771 = new BoundingRectangle(115, 122, 102,105);
  returnList.push_back(r771);

  BoundingRectangle* r772 = new BoundingRectangle(120, 122, 98,100);
  returnList.push_back(r772);

  BoundingRectangle* r773 = new BoundingRectangle(110, 127, 110,112);
  returnList.push_back(r773);

  BoundingRectangle* r774 = new BoundingRectangle(111, 126, 109,117);
  returnList.push_back(r774);

  BoundingRectangle* r775 = new BoundingRectangle(113, 126, 108,126);
  returnList.push_back(r775);

  BoundingRectangle* r776 = new BoundingRectangle(98, 109, 122,126);
  returnList.push_back(r776);

  BoundingRectangle* r777 = new BoundingRectangle(116, 127, 106,106);
  returnList.push_back(r777);

  BoundingRectangle* r778 = new BoundingRectangle(97, 109, 124,124);
  returnList.push_back(r778);

  BoundingRectangle* r779 = new BoundingRectangle(121, 122, 101,102);
  returnList.push_back(r779);

  BoundingRectangle* r780 = new BoundingRectangle(123, 123, 99,102);
  returnList.push_back(r780);

  BoundingRectangle* r781 = new BoundingRectangle(124, 127, 98,98);
  returnList.push_back(r781);

  BoundingRectangle* r782 = new BoundingRectangle(124, 127, 100,106);
  returnList.push_back(r782);

  BoundingRectangle* r783 = new BoundingRectangle(125, 127, 99,106);
  returnList.push_back(r783);

  BoundingRectangle* r784 = new BoundingRectangle(123, 127, 104,106);
  returnList.push_back(r784);

  BoundingRectangle* r785 = new BoundingRectangle(112, 125, 118,127);
  returnList.push_back(r785);

  BoundingRectangle* r786 = new BoundingRectangle(111, 125, 119,127);
  returnList.push_back(r786);

  BoundingRectangle* r787 = new BoundingRectangle(108, 109, 127,127);
  returnList.push_back(r787);

  BoundingRectangle* r788 = new BoundingRectangle(127, 127, 113,127);
  returnList.push_back(r788);

  return returnList;
}
