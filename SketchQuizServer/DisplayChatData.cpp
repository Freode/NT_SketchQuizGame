#include "stdafx.h"

void InitializeChatListView(HWND hWnd) {
    g_hChatListView = CreateWindowEx(0, WC_LISTVIEW, _T("Chat Data"),
        WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_SINGLESEL,
        220, 10, 350, 240, hWnd, NULL, NULL, NULL);

    // ù ��° �� �߰� (���̵�)
    LVCOLUMN lvc1;
    lvc1.mask = LVCF_TEXT | LVCF_WIDTH;
    lvc1.cx = 100;  // ù ��° ���� �ʺ� ����
    lvc1.pszText = (LPWSTR)_T("ID");  // ù ��° ���� "Time" ǥ��
    ListView_InsertColumn(g_hChatListView, 0, &lvc1);

    // �� ��° �� �߰� (�޽���)
    LVCOLUMN lvc2;
    lvc2.mask = LVCF_TEXT | LVCF_WIDTH;
    lvc2.cx = 250;  // �� ��° ���� �ʺ� ����
    lvc2.pszText = (LPWSTR)_T("Message");  // �� ��° ���� "Message" ǥ��
    ListView_InsertColumn(g_hChatListView, 1, &lvc2);
}

void AddChatMessageToListView(_TCHAR* id, _TCHAR* message) {
    LVITEM lvItem = { 0 };
    lvItem.mask = LVIF_TEXT | LVIF_PARAM;
    lvItem.iItem = 0;
    lvItem.iSubItem = 0;

    // ���̵� �߰�
    lvItem.pszText = id;

    // ù ��° ���� ���̵� �߰�
    int index = ListView_InsertItem(g_hChatListView, &lvItem);

    // �� ��° ���� �޽��� �߰�
    ListView_SetItemText(g_hChatListView, index, 1, message);
    DisplayChatList();
}

// ä�� ������ ����� ������ â�� ǥ��
void DisplayChatList() {
    // ä�� �����Ͱ� ����Ǿ��� �� ȣ���Ͽ� ����Ʈ �並 ������Ʈ�մϴ�.
    ListView_RedrawItems(g_hChatListView, 0, ListView_GetItemCount(g_hChatListView) - 1);
    UpdateWindow(g_hChatListView);
}