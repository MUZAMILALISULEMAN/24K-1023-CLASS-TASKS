  #include<iostream>
using namespace std;

class Song {
    public:
        string title;
        Song * next;

        Song(string title=""):title(title),next(nullptr){}
};

class Playlist {
    public:
        Song * head;
        Song * tail;

        Playlist() {
            head = nullptr;
            
            tail = nullptr;
        }

        void insertSong(string songTitle) {
            Song * n = new Song(songTitle);
            if(head == nullptr) {
                head = n;
                tail = n;
                n->next = head; 
                return;
            }
            tail->next = n;
            tail = n;
            tail->next = head;
        }

        void deleteSongFromFront() {
            if(head == nullptr) return;

            if(head == tail) { 
            
                delete head;
                head = nullptr;
                
                tail = nullptr;
                return;
            }

            Song * temp = head;
            head = head->next;
            tail->next = head; 
            delete temp;
        }

        bool searchSong(string title) {
            if(head == nullptr) return false;

            Song * temp = head;
            do {
                if(temp->title == title) {
                    cout << endl << title << " is in the playlist" << endl;
                    return true;
                }
                temp = temp->next;
            } while(temp != head);

            cout << endl << title << " is not in the playlist" << endl;
            return false;
        }

        int searchPosition(string title) {
            if(head == nullptr) return -1;

            int pos = 0;
            Song * temp = head;
            do {
                pos++;
                if(temp->title == title) {
                    cout << endl << title << " is at position " << pos << endl;
                    return pos;
                
				}
                
                temp = temp->next;
            } while(temp != head);

            cout << endl << title << " is not here" << endl;
            return -1;
        }

        void display() {
            if(head == nullptr) return;

            cout << endl;
            Song * temp = head;
            do 
			{
                cout << " -> " << temp->title;
                temp = temp->next;
                
            } while(temp != head);
            cout << " -> "<<head->title<< endl;
        }
};

int main() {
    Playlist p1;
    
    p1.insertSong("SONG 1");
    p1.insertSong("SONG 2");
    
    p1.insertSong("SONG 3");

    p1.display();
    p1.searchSong("SONG 2");
    p1.searchPosition("SONG 2");


    p1.deleteSongFromFront();
    
    p1.display();
    

    return 0;
}
