// Copyright 2016 Yahoo Inc. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.
#pragma once

#include "componentguard.h"

namespace search {

template <typename T>
ComponentGuard<T>::ComponentGuard() :
    _component(),
    _generationGuard()
{ }

template <typename T>
ComponentGuard<T>::ComponentGuard(const Component & component) :
    _component(component),
    _generationGuard(valid() ? _component->takeGenerationGuard() : Guard())
{ }

template <typename T>
ComponentGuard<T>::ComponentGuard(const ComponentGuard & rhs) :
        _component(rhs._component),
        _generationGuard(rhs._generationGuard)
{ }

template <typename T>
ComponentGuard<T> &
ComponentGuard<T>::operator = (const ComponentGuard & rhs) {
    ComponentGuard<T> tmp(rhs);
    *this = std::move(tmp);
    return *this;
}

template <typename T>
ComponentGuard<T>::~ComponentGuard() { }

}