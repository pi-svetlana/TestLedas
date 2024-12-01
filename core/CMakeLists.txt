set(target intersect)

add_library(${target}
        SHARED
        Segment3D.h
        Segment3D.cc
        Vector3D.h
        Vector3D.cc
)

include_directories(.)