//
// Created by lucja on 18.06.2024.
//

#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include "State.hpp"

#include <memory>
#include <map>

template <typename T>
class FiniteStateMachine
{
protected:
    std::map<T, std::unique_ptr<State<T>>> mStates;
    State<T>* mCurrentState;
public:
    FiniteStateMachine()
            : mCurrentState(nullptr)
    {}

    template <class S>
    State<T>& Add(T id)
    {
        static_assert(not std::is_same<State<T>, S>());
        mStates[id] = std::make_unique<S>(*this);
        return *mStates[id];
    }

    State<T>& getState(T stateID)
    {
        return *mStates[stateID];
    }

    State<T>& getCurrentState()
    {
        return *mCurrentState;
    }


    const State<T>& getCurrentState() const
    {
        return *mCurrentState;
    }


    void setCurrentState(T stateID)
    {
        State<T>* state = &getState(stateID);
        setCurrentState(state);
    }

    void onUpdate()
    {
        if (mCurrentState != nullptr)
        {
            mCurrentState->onUpdate();
        }
    }
protected:

    void setCurrentState(State<T>* state)
    {
        if (mCurrentState == state)
        {
            return;
        }
        if (mCurrentState != nullptr)
        {
            mCurrentState->onExit();
        }
        mCurrentState = state;
        if (mCurrentState != nullptr)
        {
            mCurrentState->onEnter();
        }
    }
};

#endif //STATEMACHINE_HPP
