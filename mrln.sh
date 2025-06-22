#!/usr/bin/env sh

package_add_vec() {
    echo "adding vec with args: $@"
}

package_add_set() {
    echo "adding set with args: $@"
}

package_add_map() {
    echo "adding map with args: $@"
}

package_add() {
    case $1 in
        vec)
            shift
            package_add_vec "$@"
        ;;
        map)
            shift
            package_add_map "$@"
        ;;
        set)
            shift
            package_add_set "$@"
        ;;
        *)
            >&2 echo "ERROR: add does not support adding '$1'"
            >&2 echo "HELP: supported options are:"
            >&2 echo "    vec ... for adding a vector"
            >&2 echo "    map ... for adding a map"
            >&2 echo "    set ... for adding a set"
            exit 1
        ;;
    esac
}

case $1 in
    add)
        shift
        package_add "$@"
    ;;
    *)
        >&2 echo "ERROR: argument '$1' not recognized"
        >&2 echo "HELP: available are:"
        >&2 echo "    add ... adding a package"
        >&2 exit 1
    ;;
esac
