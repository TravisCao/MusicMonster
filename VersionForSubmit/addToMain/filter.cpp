
#include "filter.h"
#include "string.h"
#include "stdlib.h"
#include "cstring"
#include "iostream"
#include <windows.h>
using namespace std;
// *********************************************************************************
// 测试模块
// **********************************************************************************
/* int main()
{
    filter("C:\\Users\\caiha\\Desktop\\filter\\a.exe",
           "C:\\Users\\caiha\\Desktop\\filter\\song.wav",
           "C:\\Users\\caiha\\Desktop\\filter\\output11.wav",
           "lowpass",
           "50",
           "20",
           " ");
    return 0;
} */
// **************************************************************************************




// *************************************************************************************
// 效果说明
// *************************************************************************************
//Filters:
//      lowpass     低通滤波器 低于设定的频率会被通过，高于设定的频率会被cutoff
//      highpass    高通滤波器 高于设定的频率会被通过，低于设定的频率会被cutoff
//      bandpass    带通滤波器 允许通过一定范围内的频率， 其余呗cutoff
//      notch       带阻滤波器 不允许通过一定范围内的频率， 其余被保留
//      peaking     峰值滤波器 对特定区域的频率进行加强或者减弱
//      lowshelf    低架滤波器 对特定区域之下的频率加强或者减弱
//      highshelf   高价滤波器 对特定区域之上的频率加强或者减弱


// 每种滤波器的参数说明
//
//    lowpass <cutoff> <resonance>
//      cutoff     截止频率 (Hz)
//      resonance  截止频率周围的泛音强度 （0-50）
//
//    highpass <cutoff> <resonance>
//      cutoff     截止频率 (Hz)
//      resonance  截止频率周围的泛音强度 （0-50）
//
//    bandpass <freq> <Q>
//      freq       设定频率 (Hz)
//      Q          上下频率范围
//
//    notch <freq> <Q>\n"
//      freq       设定频率 (Hz)
//      Q          上下频率范围
//
//   peaking <freq> <Q> <gain>
//      freq       设定频率 (Hz)
//      Q          上下频率范围
//      gain       增加的分贝强度 (dB)
//
//    lowshelf <freq> <Q> <gain>
//      freq       设定频率 (Hz)
//      Q          上下频率范围
//      gain       增加的分贝强度 (dB)
//
//    highshelf <freq> <Q> <gain>
//      freq       设定频率 (Hz)
//      Q          上下频率范围
//      gain       增加的分贝强度 (dB)
// **********************************************************************************************************************





// 格式：  exe地址；输入的wav文件地址；wav输出的地址及文件名；滤波器名字；参数1；参数2；参数3
// 例子："C:\\Users\\caiha\\Desktop\\filter\\a.exe"，
// "C:\\Users\\caiha\\Desktop\\filter\\song.wav"，
// "C:\\Users\\caiha\\Desktop\\filter\\output6.wav"，
// "lowpass"，
// "20"，
// "2"，
// " "
void filter(string address, string input   ,string output     , string filter, string para_1, string para_2 = nullptr, string para_3 = nullptr ){
    string instruction;
    instruction = address + " " + input + " " + output + " " + filter + " " + para_1 + " " + para_2 + " " + para_3;
    const char*ins = instruction.c_str();
    WinExec(ins,SW_NORMAL);
}
