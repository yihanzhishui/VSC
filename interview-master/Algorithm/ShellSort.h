void InOrderThreading(BiThrTree &Thrt, BiThrTree T) {
    Thrt = new BiThrNode; // 建头结点
    Thrt->LTag = 0; // 头结点有左孩子、若树非空，则其左孩子为树根
    Thrt->RTag = 1;      // 头结点的右孩子指针为右线索
    Thrt->rchild = Thrt; // 初始化时右指针指向自己
    if (!T)
        Thrt->lchild = Thrt; // 若树为空，则左指针也指向自己
    else {
        Thrt->lchild = T;
        pre = Thrt; // 头结点的左孩子指向根，pre初值指向头结点
        InThreading(T);
        pre->rchild = Thrt;
        pre->RTag = 1;
        Thrt->rchild = pre; // 头结点的右线索指向pre
    }
}