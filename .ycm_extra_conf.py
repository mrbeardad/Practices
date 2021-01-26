def Settings( **kwargs ):
    return { 'flags': [ '-x', 'c++', '-std=c++17', '-fcoroutine', '-I.', '-Iinclude', '-O2' ], }
