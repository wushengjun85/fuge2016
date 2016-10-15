#ifndef _LIB_FGS_H_
#define _LIB_FGS_H_

#ifdef __cplusplus   
extern "C" {   
#endif

//打开蜂鸣器
//return:1,成功;-1\-2,失败
int beep_on();
//打开蜂鸣器,滴滴
int beep_on_s();
//关闭蜂鸣器
//return:1,成功;-1\-2,失败
int beep_off();
void Set_IO_H(int gpion);
void Set_IO_L(int gpion);
//倒车信号关闭
//channel:取值{1,2,3},代表通道号
//return:1,成功;0,失败
void Cam_Power_on(int channel);
//摄像头电源关闭
//channel:取值{1,2,3,4},代表通道号
//return:1,成功;0,失败
void Cam_Power_off(int channel);
//倒车信号开启
//channel:取值{1,2,3},代表通道号
//return:1,成功;0,失败
void Acc_Sig_on(int channel);
//倒车信号关闭
//channel:取值{1,2,3},代表通道号
//return:1,成功;0,失败
void Acc_Sig_off(int channel);
//切换视频信号源到ARM输出
void Sig_to_arm();
//切换视频信号源到视频硬解板输出
void Sig_to_video();
//切换声音信号源到GSM电话模块
void Audio_to_GSM();
//切换声音信号源到ARM多媒体
void Audio_to_ARM();
//静音
void Mute_on();
//关闭静音
void Mute_off();
//打开GPRS电源
void GSM_GPS_PWR_ON();
//关闭GPRS电源
void GSM_GPS_PWR_OFF();
void GSM_RST();
int init_comm(int fd);
int SetComm(char *devname, char *SetString, unsigned int baud, int xon, int delay);
int wait_str(int comm_fd, const char *pOK);
int send_at(int fd, const char *pat, const char *pOK);
int gsmGetCSQ(int fd);
int Open_Gprs();
int Gprs_Init(int tty);
int Call(int tty,char *telno);
int Chup(int tty);
int Gprs_close(int tty);

#ifdef __cplusplus   
}   
#endif

#endif
