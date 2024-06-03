#include <iostream>
#include<vector>
using namespace std;
class Reel {};

class Folower;

class Channel {
    vector<Folower*> folowers;
    vector<Reel*> reels;
    vector<string> comments;
    int likes;
public:
    Channel() {
        likes = 0;
    }
    void AddReel(Reel* reels) {
        this->reels.push_back(reels);
    }

    void DeleteReel(Reel* reels) {
        for (int i = 0; i < this->reels.size(); i++) {
            if (this->reels[i] == reels)
                this->reels.erase(this->reels.begin() + i);
        }
    }

    void ViewComments() {
        for (int i = 0; i < comments.size(); i++)
            cout << comments[i] << "\n";
    }

    int ViewLikes() {      
        return likes;
    }

    void SetLike(int like) {
        likes = like;
    }

    int GetLike() {
        return likes;
    }

    void AddFolower(Folower* folower) {
        folowers.push_back(folower);
    }

    void DeleteFolower(Folower* folower) {
        for (int i = 0; i < folowers.size(); i++) {
            if (folower == folowers[i]) {
                folowers.erase(folowers.begin() + i);
            }
        }
    }

    void NotifyFolowers();

    void AddComment(string comment) {
        comments.push_back(comment);
    }
};

class Folower {
public:
    void SendComment(Channel* channel, string comment) {
        channel->AddComment(comment);
    }

    void Update() {
        cout << "information updated\n";
    }

    void React() {
        cout << "react to video\n";
    }

    void ClickLike(Channel* channel) {
        channel->SetLike((channel->GetLike()) + 1);
    }
};

void Channel::NotifyFolowers() {
    for (int i = 0; i < folowers.size(); i++) {
        folowers[i]->Update();
    }
}
class User{
    Channel* channel = nullptr;
    //vector<Folower*> folowers;
public:
    User(Channel* channel) : channel(channel) {}

    Channel* GetChannel() {
        return channel;
    }

    Reel* PublishReel() {
        return new Reel;
    }


    /*void AddFolower(Folower* folower) {
        folowers.push_back(folower);
    }*/

    /*void DeleteFolower(Folower* folower) {
        for (int i = 0; i < folowers.size(); i++) {
            if (folower == folowers[i]) {
                folowers.erase(folowers.begin() + i);
            }
        }
    }*/

    /*void NotifyFolowers() {
        for (int i = 0; i < folowers.size(); i++) {
            folowers[i]->Update();
        }
    }*/
};

int main()
{
    Channel channel;
    User user(&channel);
    Folower a;
    Folower b;
    
    channel.AddFolower(&a);
    channel.AddFolower(&b);
    channel.AddReel(user.PublishReel());
    channel.NotifyFolowers();
    a.SendComment(&channel,"really nice!!\n");
    channel.ViewComments();

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
