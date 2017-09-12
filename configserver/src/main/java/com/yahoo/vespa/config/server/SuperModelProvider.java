// Copyright 2017 Yahoo Holdings. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.

package com.yahoo.vespa.config.server;

import com.yahoo.vespa.config.server.model.SuperModel;

interface SuperModelProvider {
    SuperModel getSuperModel();
    long getGeneration();

    void registerListener(SuperModelListener listener);
}
