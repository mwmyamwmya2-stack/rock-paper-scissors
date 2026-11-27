#include <cstdlib> 
#include <ctime>  
#include <iostream> 
using namespace std; 

//حركة الكمبيوتر
string getComputerChoice() {
    
    string choices[] = { "rock", "paper", "scissors" };
    int index = rand() % 3; // توليد رقم عشوائي بين 0 و 2 ليمثل فهرس الاختيار
    return choices[index];  // إرجاع الاختيار الموافق للفهرس العشوائي
}


string mapCharToChoice(char c) {
    c = tolower(c);         
    if (c == 'r')          
        return "rock";      
    if (c == 'p')           
        return "paper";    
    if (c == 's')           
        return "scissors";  
    return "";             
}

// تحديد الفائز في الجولة
string determineWinner(string player, string computer) {
    if (player == computer) // إذا تساوى الاختياران فالجولة تعادل
        return "tie";
    // حالات فوز اللاعب: حجرة تكسر المقص، أو ورقة تغلف الحجرة، أو مقص يقص الورقة
    if ((player == "rock" && computer == "scissors") ||
        (player == "paper" && computer == "rock") ||
        (player == "scissors" && computer == "paper"))
        return "player";
    else                    // باقي الحالات تعني فوز الكمبيوتر
        return "computer";
}

// دالة لتحديث النقاط وإرجاع رسالة نتيجة الجولة (تم تمرير النقاط بالمرجع & لتعديلها مباشرة)
string getResultMessage(string winner, int& playerScore, int& computerScore) {
    if (winner == "tie") {          // في حالة التعادل
        return "It's a tie";
    }
    else if (winner == "player") { // في حالة فوز اللاعب
        playerScore++;               // زيادة نقاط اللاعب بمقدار 1
        return "You win";
    }
    else {                         // في حالة فوز الكمبيوتر
        computerScore++;             // زيادة نقاط الكمبيوتر بمقدار 1
        return "You lose";
    }
}

int main() {                         // نقطة البداية لتنفيذ البرنامج
    srand(time(0));                  // تهيئة مولد الأرقام العشوائية بالوقت الحالي
    char playerChar;                 // متغير لتخزين الحرف الذي يدخله اللاعب (r / p / s)
    string playerChoice, computerChoice; // متغيران لحفظ اختيار اللاعب والكمبيوتر كنص
    int playerScore = 0, computerScore = 0; // عدّاد نقاط اللاعب والكمبيوتر ويبدآن من صفر

    int rounds;                      // متغير لتحديد عدد الجولات المطلوب لعبها

    cout << "Welcome to Rock, Paper, Scissors\n"; // رسالة ترحيب
    cout << "Enter 'r' for rock, 'p' for paper, or 's' for scissors.\n"; // توضيح الحروف
    cout << "How many rounds do you want to play? "; // سؤال المستخدم عن عدد الجولات
    cin >> rounds;                   // قراءة عدد الجولات من المستخدم

    for (int i = 1; i <= rounds; ++i) { // حلقة لتشغيل اللعبة لعدد الجولات المحدد
        cout << "\n--- Round " << i << " ---\n"; // طباعة رقم الجولة الحالية

        do {                         // حلقة لضمان إدخال حرف صحيح قبل الانتقال للخطوة التالية
            cout << "Enter your choice (r/p/s): "; // طلب اختيار اللاعب
            cin >> playerChar;                          // قراءة الحرف من اللاعب
            playerChoice = mapCharToChoice(playerChar); // تحويل الحرف إلى كلمة

            if (playerChoice == "") // إذا رجع نص فارغ فالإدخال غير صحيح
                cout << "Invalid input. Please enter 'r', 'p', or 's'.\n";

        } while (playerChoice == ""); // تكرار السؤال طالما لم يدخل اللاعب حرفًا صحيحًا

        computerChoice = getComputerChoice(); // الحصول على اختيار الكمبيوتر العشوائي
        cout << "Computer chose: " << computerChoice << endl; // عرض اختيار الكمبيوتر

        string winner = determineWinner(playerChoice, computerChoice); // تحديد الفائز بالجولة
        string result = getResultMessage(winner, playerScore, computerScore); // تحديث النتيجة والنقاط
        cout << result << endl; // طباعة نتيجة الجولة

        // عرض النقاط الحالية بعد نهاية الجولة
        cout << "Score - You: " << playerScore << " | Computer: " << computerScore
            << endl;
    }

    // طباعة النتيجة النهائية بعد انتهاء جميع الجولات
    cout << "\nGame Over! Final Score - You: " << playerScore
        << " | Computer: " << computerScore << endl;

    if (playerScore > computerScore) // إذا تفوق اللاعب في النقاط الكلية
        cout << "You are the winner\n";
    else if (playerScore < computerScore) // إذا تفوق الكمبيوتر في النقاط الكلية
        cout << "Computer wins Better luck next time.\n";
    else // إذا تساوت النقاط النهائية
        cout << " It's a tie overall.\n";

    return 0; 
}
