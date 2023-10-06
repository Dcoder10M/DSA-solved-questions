class DiningPhilosophers {
public:
    DiningPhilosophers() {
        
    }
    mutex mtx;
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
                        mtx.lock();
        pickLeftFork(); pickRightFork(); eat(); putLeftFork(); putRightFork();
        mtx.unlock();
    }
};