#pragma once

#define SERVERIP4_CHAR_UDP1 "235.7.8.18" // �׷� 1
#define SERVERIP4_CHAR_UDP2 "235.7.8.19" // �׷� 1
#define SERVERPORT 9000
#define BUFSIZE    256

// =========== ���� =============
#define CLIENTOUT 3001

// ==== ���� ====
#define TYPE_CHAT   1000
// =============

//==== ���� ===== //
#define SIZE_TOT 256                    // ���� ��Ŷ(��� + ������) ��ü ũ��
#define SIZE_DAT (SIZE_TOT-2*sizeof(int)) // ����� ������ ������ �κи��� ũ��

#define TYPE_ID		1003				// �޽��� Ÿ��: id (����)
// ============== //

// ==== ��ȣ ====
#define WM_SOCKET (WM_USER+1)

// UDP �׷� ��ȣ
#define TYPE_GROUP_A		1000000
#define TYPE_GROUP_B		2000000

// UDP Ŭ�� ����
typedef struct _UDPINFO
{
	SOCKADDR_IN addr;
	int groupNum = 0;
} UDPINFO;

// ���� ���� ������ ���� ����ü�� ����
typedef struct _SOCKETINFO
{
	SOCKET sock;
	char   buf[BUFSIZE + 1];
	int    recvbytes;
	// ===== ���� ====== 
	USHORT sin_port;	// ���� ��Ʈ ��ȣ
	IN_ADDR sin_addr;	// ���� ip �ּ� 
	char id_nickname_char[BUFSIZE]; // ����� �г��� char ����.

	// ===== ���� ======
	_TCHAR id_nickname[BUFSIZE]; // ����� �г���
	int    score = 0;       // ���� �÷��� ����
} SOCKETINFO;

// ======= ���� ======= 
typedef struct _MESSAGEQUEUE {
	char queue[BUFSIZE][100] = { NULL };         // �޽��� ���� ť: ���� ��ȭ���� ǥ��. �� ���� ���� ������ �޽������� ��������.
	int head = 0;                 // ���� ť �ε���
	int tail = 0;
} MESSAGEQUEUE;

typedef struct _CHAT_MSG
{
	int  type;
	int	 groupNum;
	char msg[SIZE_DAT];
} CHAT_MSG;

// ====================

// ======== ���� ======== //
// ���� �޽��� ����
// sizeof(COMM_MSG) == 256
typedef struct _COMM_MSG
{
	int  type;
	int	 groupNum;
	char dummy[SIZE_DAT];
} COMM_MSG;

// �α����Ҷ� ID ����
// sizeof(DRAWLINE_MSG) == 256
typedef struct ID
{
	int  type;		// �α����Ҷ� ID ����
	char msg[SIZE_DAT];	// id ����
} ID_MSG;
// ====================== //


// ========== ���� ==========
// ���̾�α� ���ν���
INT_PTR CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
// ==========================

// ���� ���� ���� �Լ�
bool AddSocketInfoTCP(SOCKET sock);
bool AddSocketInfoUDP(SOCKADDR_IN addr, int groupNum);
void RemoveSocketInfo(SOCKET sock);
void addMessage(char* message);
SOCKETINFO* GetSocketInfo(SOCKET sock);

// �ش� Ŭ���̾�Ʈ�� �׷� ���� ��������
int GetGroupNumber(SOCKADDR_IN addr);


// ������ �޽��� ó�� �Լ�
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void ProcessSocketMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);