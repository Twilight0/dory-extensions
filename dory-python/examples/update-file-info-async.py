from gi.repository import Dory, GObject

class UpdateFileInfoAsync(GObject.GObject, Dory.InfoProvider):
    def __init__(self):
        super(UpdateFileInfoAsync, self).__init__()
        pass

    def update_file_info_full(self, provider, handle, closure, file):
        print("update_file_info_full")
        GObject.timeout_add_seconds(3, self.update_cb, provider, handle, closure)
        return Dory.OperationResult.IN_PROGRESS

    def update_cb(self, provider, handle, closure):
        print("update_cb")
        Dory.info_provider_update_complete_invoke(closure, provider, handle, Dory.OperationResult.FAILED)
