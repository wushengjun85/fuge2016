#ifndef _LIB_FGS_H_
#define _LIB_FGS_H_

#ifdef __cplusplus   
extern "C" {   
#endif

//�򿪷�����
//return:1,�ɹ�;-1\-2,ʧ��
int beep_on();
//�򿪷�����,�ε�
int beep_on_s();
//�رշ�����
//return:1,�ɹ�;-1\-2,ʧ��
int beep_off();
void Set_IO_H(int gpion);
void Set_IO_L(int gpion);
//�����źŹر�
//channel:ȡֵ{1,2,3},����ͨ����
//return:1,�ɹ�;0,ʧ��
void Cam_Power_on(int channel);
//����ͷ��Դ�ر�
//channel:ȡֵ{1,2,3,4},����ͨ����
//return:1,�ɹ�;0,ʧ��
void Cam_Power_off(int channel);
//�����źſ���
//channel:ȡֵ{1,2,3},����ͨ����
//return:1,�ɹ�;0,ʧ��
void Acc_Sig_on(int channel);
//�����źŹر�
//channel:ȡֵ{1,2,3},����ͨ����
//return:1,�ɹ�;0,ʧ��
void Acc_Sig_off(int channel);
//�л���Ƶ�ź�Դ��ARM���
void Sig_to_arm();
//�л���Ƶ�ź�Դ����ƵӲ������
void Sig_to_video();
//�л������ź�Դ��GSM�绰ģ��
void Audio_to_GSM();
//�л������ź�Դ��ARM��ý��
void Audio_to_ARM();
//����
void Mute_on();
//�رվ���
void Mute_off();
//��GPRS��Դ
void GSM_GPS_PWR_ON();
//�ر�GPRS��Դ
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
