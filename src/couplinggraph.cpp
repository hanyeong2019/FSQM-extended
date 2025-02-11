//couplinggraph.cpp
#include "circuit.h"
using namespace std;
using namespace Qcircuit;

void Qcircuit::QMapper::select_coupling_graph(ARCHITECTURE archi)
{
    switch(archi)
    {
    case ARCHITECTURE::IBM_Q_20:
        build_graph_IBM_Q_20();
        break;
    case ARCHITECTURE::IBM_Q_127:
        build_graph_IBM_Q_127();
        break;
    default:
        cout << "No architecture specified!" << endl;
        exit(1);
    }
}

//build a graph representing the coupling map of IBM Q 20
void Qcircuit::QMapper::build_graph_IBM_Q_20()
{
    positions = 20;
    for(int i=0; i<positions; i++)
        coupling_graph.addnode();
    coupling_graph.addedge(0, 1);
    coupling_graph.addedge(0, 5);
    coupling_graph.addedge(1, 2);
    coupling_graph.addedge(1, 6);
    coupling_graph.addedge(1, 7);
    coupling_graph.addedge(2, 3);
    coupling_graph.addedge(2, 6);
    coupling_graph.addedge(2, 7);
    coupling_graph.addedge(3, 4);
    coupling_graph.addedge(3, 8);
    coupling_graph.addedge(3, 9);
    coupling_graph.addedge(4, 8);
    coupling_graph.addedge(4, 9);
    coupling_graph.addedge(5, 6);
    coupling_graph.addedge(5, 10);
    coupling_graph.addedge(5, 11);
    coupling_graph.addedge(6, 7);
    coupling_graph.addedge(6, 10);
    coupling_graph.addedge(6, 11);
    coupling_graph.addedge(7, 8);
    coupling_graph.addedge(7, 12);
    coupling_graph.addedge(7, 13);
    coupling_graph.addedge(8, 9);
    coupling_graph.addedge(8, 12);
    coupling_graph.addedge(8, 13);
    coupling_graph.addedge(9, 14);
    coupling_graph.addedge(10, 11);
    coupling_graph.addedge(10, 15);
    coupling_graph.addedge(11, 12);
    coupling_graph.addedge(11, 16);
    coupling_graph.addedge(11, 17);
    coupling_graph.addedge(12, 13);
    coupling_graph.addedge(12, 16);
    coupling_graph.addedge(12, 17);
    coupling_graph.addedge(13, 14);
    coupling_graph.addedge(13, 18);
    coupling_graph.addedge(13, 19);
    coupling_graph.addedge(14, 18);
    coupling_graph.addedge(14, 19);
    coupling_graph.addedge(15, 16);
    coupling_graph.addedge(16, 17);
    coupling_graph.addedge(17, 18);
    coupling_graph.addedge(18, 19);
    cout << " # This graph is: IBM Q 20" << endl
         << endl;
}

void Qcircuit::QMapper::build_graph_IBM_Q_127()
{
    positions = 127; // 0-126 总共127个量子比特
    for (int i = 0; i < positions; i++)
        coupling_graph.addnode();

    // 水平连接
    for (int i = 0; i < 13; i++)
        coupling_graph.addedge(i, i + 1);

    for (int i = 18; i < 32; i++)
        coupling_graph.addedge(i, i + 1);

    for (int i = 37; i < 51; i++)
        coupling_graph.addedge(i, i + 1);

    for (int i = 56; i < 70; i++)
        coupling_graph.addedge(i, i + 1);

    for (int i = 75; i < 89; i++)
        coupling_graph.addedge(i, i + 1);

    for (int i = 94; i < 108; i++)
        coupling_graph.addedge(i, i + 1);

    for (int i = 113; i < 126; i++)
        coupling_graph.addedge(i, i + 1);

    // 垂直连接
    coupling_graph.addedge(0, 14);
    coupling_graph.addedge(14, 18);
    coupling_graph.addedge(18, 33);
    coupling_graph.addedge(33, 37);
    coupling_graph.addedge(37, 52);
    coupling_graph.addedge(52, 56);
    coupling_graph.addedge(56, 71);
    coupling_graph.addedge(71, 75);
    coupling_graph.addedge(75, 90);
    coupling_graph.addedge(90, 94);
    coupling_graph.addedge(94, 109);
    coupling_graph.addedge(109, 113);

    coupling_graph.addedge(4, 15);
    coupling_graph.addedge(15, 22);
    coupling_graph.addedge(22, 34);
    coupling_graph.addedge(34, 43);
    coupling_graph.addedge(43, 53);
    coupling_graph.addedge(53, 60);
    coupling_graph.addedge(60, 72);
    coupling_graph.addedge(72, 81);
    coupling_graph.addedge(81, 91);
    coupling_graph.addedge(91, 98);
    coupling_graph.addedge(98, 110);
    coupling_graph.addedge(110, 117);

    coupling_graph.addedge(8, 16);
    coupling_graph.addedge(16, 26);
    coupling_graph.addedge(26, 35);
    coupling_graph.addedge(35, 45);
    coupling_graph.addedge(45, 54);
    coupling_graph.addedge(54, 64);
    coupling_graph.addedge(64, 73);
    coupling_graph.addedge(73, 83);
    coupling_graph.addedge(83, 92);
    coupling_graph.addedge(92, 102);
    coupling_graph.addedge(102, 111);
    coupling_graph.addedge(111, 121);

    coupling_graph.addedge(13, 17);
    coupling_graph.addedge(17, 31);
    coupling_graph.addedge(31, 36);
    coupling_graph.addedge(36, 51);
    coupling_graph.addedge(51, 55);
    coupling_graph.addedge(55, 70);
    coupling_graph.addedge(70, 74);
    coupling_graph.addedge(74, 89);
    coupling_graph.addedge(89, 93);
    coupling_graph.addedge(93, 108);
    coupling_graph.addedge(108, 112);
    coupling_graph.addedge(112, 126);

    // 特殊连接（紫色线）
    coupling_graph.addedge(20, 33);
    coupling_graph.addedge(38, 62);
    coupling_graph.addedge(62, 72);
    coupling_graph.addedge(91, 98);
    cout << " # This graph is: IBM Q 127" << endl
         << endl;
}
