

#pragma once

class Application {
    public:
        virtual ~Application() = default;

         virtual void run() = 0;
         virtual void initialize() = 0;
         virtual void cleanup() = 0;
};
